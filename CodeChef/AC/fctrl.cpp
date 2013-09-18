#include<iostream>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int div=5;
    int res=0;
    while(div<=n){
      res+=n/div;
      div*=5;
    }
    cout << res << '\n';
  }
}
