#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

const int N=600;

const vector<int> d{1,18,4,13,6,10,15,2,17,3,19,7,16,8,11,14,9,12,5,20,1,18};
const int D=d.size()-2;
vector<vector<double> > pa(N,vector<double>(N));
vector<vector<double> > pb(N,vector<double>(N));

int main(){
  for(int i=0;i<N;++i)
    pa[0][i]=pb[i][0]=1;

  for(int n=1;n<N;++n)
    for(int m=1;m<N;++m){

      if(n<=D) pa[n][m]=n/20.;
      if(m<=D) pb[n][m]=m/3.;

      for(int tries=0;tries<100;++tries){
	double a=0;
        for (int i=1;i<=D;++i)
          a+=pb[(n>=d[i])?n-d[i]:n][m];
        pa[n][m]=1-a/D;

        double b=1e300;
        for (int i=1;i<=D;++i){
          double val=0;
          for (int j=-1;j<=1;++j)
            val+=pa[n][(m>=d[i+j])?m-d[i+j]:m];
          val/=3;
	  b=min(b,val);
        }
        pb[n][m]=1-b;
        if(n>D) break;
      }
    }

  int n;
  while(cin >> n && n)
    cout << fixed << setprecision(8) << pa[n][n] << ' ' << pb[n][n] << '\n';
}
