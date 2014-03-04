#include <iostream>
#include <cmath>

using namespace std;

int const N=100000;

int tab[N];

int div(int n, int q, int compt){
  if(n==0) return 0;
  if(n<q) return div(10*n,q,compt);
  if(tab[n]!=-1) return compt-tab[n];
  tab[n]=compt;
  return div((n%q)*10,q,compt+1);
}

int main(){
  int res=0;
  int dmax=0;
  for(int d=1;d<1000;++d){
    for(int i=0;i<N;++i)
      tab[i]=-1;
    int tmp=div(1,d,0);
    if(res<tmp){
      res=tmp;
      dmax=d;
    }
  }
  cout << dmax << ' ' << res << '\n';
}
