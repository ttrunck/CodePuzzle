#include<iostream>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n,k;
  cin >> n >> k;
  int res=0;
  while(n--){
    int tmp;
    cin >> tmp;
    if(tmp%k==0)
      ++res;
  }
  cout << res << '\n';
}
