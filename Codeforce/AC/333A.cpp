#include<iostream>

using namespace std;

typedef long long ll;

int main(){
  ll n;
  cin >> n;

  ll coin = 1;
  while(n%coin==0)
    coin*=3;
  cout << n/coin+1 << endl;
}
