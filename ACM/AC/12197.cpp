#include<iostream>
#include<vector>
#include<utility>
#include<complex>
#include<iomanip>

using namespace std;

typedef complex<double> com;

const double epsi=1e-8;

bool droite(com x, const vector<com> & t){
  double dist=0;
  bool res;
  for(int i=0;i<int(t.size());++i){
    double tmp=abs(t[i]-x);
    if(tmp>dist){
      dist=tmp;
      res=(t[i].real()>x.real());
    }
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  int n;
  while(cin >> n && n){
    vector<com> t(n);
    for(int i=0;i<n;++i){
      double r,im;
      cin >> r >> im;
      t[i]=complex<double>{r,im};
    }
    double lo=-200000, hi=200000;
    while(hi-lo>epsi){
      double x=(hi+lo)/2;
      if(droite(com(x), t))
	lo=x;
      else
	hi=x;
    }

    double dist=0;
    for(int i=0;i<n;++i)
      dist=max(dist, abs(t[i]-com(lo)));

    cout << fixed << setprecision(6) << lo << ' ' << dist << '\n';
  }
}
