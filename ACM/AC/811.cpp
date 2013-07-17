#include<iostream>
#include<algorithm>
#include<complex>
#include<vector>
#include<iomanip>
#include<cmath>

using namespace std;

typedef complex<double> point;
typedef vector<point> poly;

double inline det(const point &u, const point &v) { return imag(conj(u) * v); }

struct Compare{
  point p0; // Leftmost point of the poly
  bool operator ()(const point &p1, const point &p2) {
    if (p1 == p0) return true;
    if (p2 == p0) return false;
    double d = det(p1-p0, p2-p0);
    return (d<0 || (d==0 && abs(p1-p0) < abs(p2-p0)));
  }
};

bool inline salientAngle(const point & a, const point & b, const point & c) {
  return (det(b-a, c-a) >= 0);
}

void convexHull(poly &t, poly &r){
  Compare order;
  order.p0 = t[0];
  for(int i=0;i<int(t.size());++i)
    if (t[i].real() < order.p0.real())
      order.p0 = t[i];
  sort(t.begin(), t.end(), order);
  for(int i=0; i<int(t.size());++i){
    r.push_back(t[i]);
    while (r.size() > 3 && salientAngle(r.end()[-3], r.end()[-2], r.end()[-1])) {
      r.end()[-2] = r.back();
      r.pop_back();
    }
  }
}

double perim(const poly &t){
  double res=0;
  int n=t.size();
  for(int i=0;i<n;++i)
    res+=abs(t[(i+1)%n]-t[i]);
  return res;
}

struct arbre{
  point p;
  int val, size;
  arbre(int a=0, int b=0, int c=0, int d=0):p(a,b),val(c),size(d){};
};

int main(){
  int n;
  int icase=1;
  while(cin >> n && n){
    if(icase!=1)
      cout << '\n';
    cout << "Forest " << icase++ << '\n';
    vector<arbre> t(n);
    for(int i=0;i<n;++i){
      int a,b,c,d;
      cin >> a >> b >> c >> d;
      t[i]=arbre(a,b,c,d);
    }

    vector<int> cut;
    double reste=0;
    double val=0;
    for(int k=0;k<(1<<n);++k){
      int kk=k;
      poly po;
      double planche=0, tmpval=0;
      vector<int> tmpcut;
      for(int i=0;i<n;++i){
	if(kk%2==0){
	  po.push_back(t[i].p);
	  tmpval+=t[i].val;
	}
	else{
	  tmpcut.push_back(i);
	  planche+=t[i].size;
	}
	kk/=2;
      }
      if(val>tmpval || (tmpval==val && tmpcut.size()>cut.size())) continue;
      vector<point> r;
      convexHull(po,r);
      // cerr << k << ' ' << perim(r) << ' ' << planche << ' ' << val << ' ' << tmpval << endl;
      if(perim(r)<=planche){
	cut=tmpcut;
	reste=planche-perim(r);
	val=tmpval;
      }
    }

    cout << "Cut these trees:";
    for(int i=0;i<int(cut.size());++i)
      cout << ' ' << cut[i]+1;
    cout << '\n';
    cout << "Extra wood: " << fixed << setprecision(2) << reste << '\n';
  }
}
