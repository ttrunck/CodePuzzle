#include<iostream>

using namespace std;

int exp(int a, int b, int mod){
  if(b==0) return 1;
  int tmp = exp(a,b/2,mod);
  tmp = (tmp * tmp)%mod;

  if(b%2==0)
    return tmp;
  return (tmp*a)%mod;
}

int main(){
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  while(N--){
    int x,y,n;
    cin >> x >> y >> n;
    cout << exp(x,y,n) << '\n';
  }
}
