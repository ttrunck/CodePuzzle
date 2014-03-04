#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<gmpxx.h>

using namespace std;

typedef mpq_class ff;
typedef mpz_class ent;

int const DD=1000;

bool is_square(int n){
  int tmp=sqrt(n);
  return tmp*tmp==n;
}

int gcd(int a,int b){
  if(b==0) return a;
  return gcd(b,a%b);
}

struct step{
  int a,b,c,d,n;
};

step f(step k){
  step kk;
  kk.n=k.n;
  kk.c=k.b*k.b*k.n-k.d*k.d;
  int tmp=gcd(k.c,kk.c);
  kk.a=k.c*(k.b*((int) sqrt(k.n))-k.d)/kk.c;
  kk.b=k.c*k.b/tmp;
  kk.d=(-k.c*k.d-kk.a*kk.c)/tmp;
  kk.c/=tmp;
 return kk;
}

void print(step k){
  cout << k.a << ' ' << k.b << ' ' << k.c << ' ' << k.d << ' ' << k.n << '\n';
}

bool operator==(step a, step b)
{
  return (a.a==b.a)&&(a.b==b.b)&&(a.c==b.c)&&(a.d==b.d)&&(a.n==b.n);
}

step init(int n){
  step res;
  res.a=sqrt(n);
  res.b=1;
  res.c=1;
  res.d=-sqrt(n);
  res.n=n;
  return res;
}

vector<int> red(int n){
  vector<int> res;
  vector<step> t;
  step k=init(n);
  while(! count(t.begin(),t.end(),k)>=1){
    t.push_back(k);
    res.push_back(k.a);
    k=f(k);
  }
  return res;
}


ent sol(int d){
  vector<int> t=red(d);
  /*
  for(int i=0;i<t.size();++i)
    cout << t[i] << ' ';
  cout <<'\n';
  */
  int m=t.size()-1;
  ff frac;
  if(m%2==0){
    frac=t[m-1];
    for(int i=m-2;i>=0;--i)
      frac=(ff)t[i]+1/frac;
  }
  else{
    frac=t[(2*m-1)%(m+1)];
    for(int i=2*m-2;i>=0;--i)
      frac=(ff)t[i%(m+1)]+1/frac;
  }
  cout << frac << '\n';
  return frac.get_num();
}

int main(){
  ent dmax=-1, xmax=0; 
  for(int i=2;i<=DD;++i){
    if(is_square(i)) continue;
    ent xtmp=sol(i);
    if(xtmp>xmax){
      xmax=xtmp;
      dmax=i;
    }
  }

  cout << dmax << '\n';

}
