#include<iostream>

using namespace std;

typedef long long ll;

const int MOD=1000000007;

ll pow(ll a, ll b){
  if(b==0) return 1;
  ll tmp=pow(a,b/2);
  tmp=(tmp*tmp)%MOD;
  if(b%2==1)
    tmp=(tmp*a)%MOD;
  return tmp;
}

int main(){
  int nbcase;
  cin >> nbcase;
  while(nbcase--){
    ll n;
    cin >> n;
    cout << (pow(2,n)-1+MOD)%MOD << '\n';
  }
}
