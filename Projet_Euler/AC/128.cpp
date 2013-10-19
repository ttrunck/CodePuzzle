#include<iostream>

using namespace std;

typedef long long ll;

ll isPrime(ll n){
  for(ll i=2;i*i<=n;++i)
    if(n%i==0)
      return false;
  return true;
}

int main(){
  ll n=1;
  int comp=2000;
  while(comp){
    if(isPrime(6*n+1) && isPrime(6*n-1) && isPrime(6*(2*n+1)-1)){
      comp--;
      if(comp==0)
	cout << 3*n*n - 3*n + 2 << endl;
    }
if(isPrime(6*n+5) && isPrime(6*n-1) && isPrime(6*(2*n-1)-1)){
      comp--;
      if(comp==0)
	cout << 3*n*n + 3*n + 1 << endl;
    }


    n++;
  }
}
