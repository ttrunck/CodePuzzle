#include<iostream>
#include<iomanip>

using namespace std;

const int N=509;
double t[N][N];
double pow[N];

int main(){
  int n;
  double p;
  while(cin >> n >> p && n){
    pow[0]=1;
    for(int i=1;i<=n;++i)
      pow[i]=pow[i-1]*p;

    for(int i=0;i<=n;++i)
      for(int j=i;j<=n;++j)
	t[i][j]=1;
    for(int i=1;i<=n;++i)
      t[i][i-1]=1-pow[i];
    for(int i=2;i<=n;++i)
      for(int j=0;j<=i-2;++j)
	t[i][j]=t[i-1][j]-pow[j+1]*(1-p)*t[i-2-j][j];
    double res=0;
    for(int j=0;j<=n;++j)
      res+=j*(t[n][j]-t[n][j-1]);
    cout << fixed << setprecision(6) << res << '\n';
  }
}
