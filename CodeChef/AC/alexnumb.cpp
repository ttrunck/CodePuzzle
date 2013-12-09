#include<iostream>

using namespace std;

typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while(T-->0){
    ll n;
    int tmp;
    cin >> n;
    cout << (n*(n-1))/2 << '\n';
    for(int i=0;i<n;++i)
      cin >> tmp;
  }
}
