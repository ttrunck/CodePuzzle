#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

double adv(double p){
  return (p*p)/(1-2*p*(1-p));
}

double calc(int n, double p, double q){
  vector<vector<double> > t(n+1, vector<double>(n+1));
  for(int j=0;j<=n-2;++j)
    t[n][j]=1;
 for(int i=0;i<=n-2;++i)
    t[i][n]=0;
  t[n][n]=q;
  t[n][n-1]=p+(1-p)*t[n][n];
  t[n-1][n]=p*t[n][n];

  for(int i=n-1;i>=0;--i)
    for(int j=n-1;j>=0;--j)
      t[i][j]=p*t[i+1][j]+(1-p)*t[i][j+1];

  return t[0][0];
}

int main(){
  double p;
  while(cin >> p && p!=-1){
    double pgame=calc(4,p,adv(p));
    double ptie=calc(7,p,adv(p));
    double pset=calc(6,pgame,ptie);
    double pmatch=pset*pset+2*pset*pset*(1-pset);
    cout << fixed << setprecision(11) << pgame << ' ' << pset << ' ' << pmatch << '\n';
  }
}
