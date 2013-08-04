#include<iostream>

using namespace std;

int main(){
  int T;
  cin >> T;
  while(T--){
    double d;
    int u, n;
    cin >> d >> u >> n;
    int res=0;
    double best=d*u;
    for(int i=1;i<=n;++i){
      int m;
      double r,c;
      cin >> m >> r >> c;
      if(best>(u*r+c/m)){
	res=i;
	best=(u*r+c/m);
      }
    }

    cout << res << '\n';
  }
}
