#include<iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  for(int i=1;i<=4;++i){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(min(a,b)+min(c,d)<=n){
      cout << i << ' ' << min(a,b) << ' ' << n-min(a,b) << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
}
