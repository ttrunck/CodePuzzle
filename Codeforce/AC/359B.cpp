#include<iostream>

using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  for(int i=1;i<=k;++i)
    cout << 2*i << ' ' << 2*i-1 << ' ';

  for(int i=k+1;i<=n;++i)
    cout << 2*i-1 << ' ' << 2*i << ' ';
}
