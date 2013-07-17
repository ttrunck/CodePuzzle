#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

typedef long long ent;

ent gcd(ent a, ent b){
  if(b==0) return a;
  return gcd(b,a%b);
}

struct frac{
  ent n,d;
  frac(ent aa=0, ent bb=1){
    ent tmp=gcd(aa,bb);
    n=aa/tmp;
    d=bb/tmp;
  }

  void simplify(){
    ent tmp=gcd(n,d);
    n/=tmp;
    d/=tmp;
    if(d<0){
      n=-n;
      d=-d;
    }
  }

  bool operator!=(const frac & f){
    return n*f.d!=f.n*d;
  }
  void operator+=(const frac & f){
    n=f.n*d+n*f.d;
    d*=f.d;
    simplify();
  }
  void operator*=(const frac & f){
    n*=f.n;
    d*=f.d;
    simplify();
  }

};

frac operator*(const frac & a, const frac & b){
  frac res=a;
  res*=b;
  return res;
}

ostream& operator<<(ostream& out, const frac & f){
  out << f.n;
  if(f.d!=1){
    out << '/' << f.d;
  }
  return out;
}

istream& operator>>(istream& in, frac & f){
  string s;
  in >> s;
  istringstream ss(s);
  ent a,b=1;
  char tmp;
  ss >> a;
  if(ss >> tmp)
    ss >> b;
  f=frac(a,b);
  return in;
}

void print(const vector<vector<frac> > & t){
for(int i=0;i<int(t.size());++i){
      for(int j=0;j<int(t[i].size());++j)
	cerr << t[i][j] << ' ';
      cerr << '\n';
    }
 cerr << "------\n\n";
}

bool findnot0(int m, int n, vector<vector<frac> > & t){
  for(int i=m;i<int(t.size());++i)
    if(t[i][n]!=0){
      swap(t[i], t[m]);
      return true;
    }
  return false;
}

void set1(int m, int n, vector<vector<frac> > & t){
  frac tmp(t[m][n].d, t[m][n].n);
  for(int i=0;i<int(t[m].size());++i)
    t[m][i]*=tmp;
}

void propagate(int m, int n, vector<vector<frac> > & t){
  for(int i=0;i<int(t.size());++i){
    if(i==m) continue;
    frac tmp(-t[i][n].n, t[i][n].d);
    for(int j=0;j<int(t[i].size());++j)
      t[i][j]+=t[m][j]*tmp;
  }
}

int solve(vector<vector<frac> > & t, vector<frac> & sol){
  int rg=0;
  int x=(int(t[0].size())-1);
  for(int i=0;i<x;++i){
    if(findnot0(rg, i, t)){
      set1(rg, i, t);
      propagate(rg, i, t);
      rg++;
    }
  }

  //err << "rang= " << rg << endl;
  //print(t);

  if(findnot0(rg,x, t))
    return 0;

  if(rg==x){
    for(int i=0;i<int(sol.size());++i)
    sol[i]=t[i][t[i].size()-1];
  return -1;
  }

  return x-rg;
}

int main(){
  int n;
  bool first=true;
  while(cin >> n && n){
    if(!first)
      cout << '\n';
    first=false;
    cout << "Solution for Matrix System # " << n << '\n';
    int x,e;
    cin >> x >> e;
    vector<vector<frac> > t(e, vector<frac>(x+1));
    for(int i=0;i<e;++i)
      for(int j=0;j<=x;++j)
	cin >> t[i][j];

    vector<frac> sol(x);
    int nbsol = solve(t,sol);
    if(nbsol==-1){
      for(int i=0;i<x;++i)
	cout << "x[" << i+1 << "] = " << sol[i] << '\n';
    }
    else if(nbsol==0)
      cout << "No Solution.\n";
    else
      cout << "Infinitely many solutions containing " << nbsol << " arbitrary constants.\n";

}
}
