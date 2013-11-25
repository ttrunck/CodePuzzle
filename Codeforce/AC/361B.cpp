#include<iostream>

using namespace std;

int main(){
  int n, k;
  cin >> n >> k;

  if(n==k)
    cout << "-1\n";
  else{
    cout << n-k;
    for(int i=1;i<n-k;++i)
      cout << ' ' << i;
    for(int i=n-k+1;i<=n;++i)
      cout << ' ' << i;
    cout << '\n';
  }
}
