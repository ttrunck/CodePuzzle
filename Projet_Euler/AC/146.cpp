#include<iostream>

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/miller_rabin.hpp>

using namespace std;

typedef long long ll;
const int N=150000000;

/*
bool isPrime(ll n){
  if (n == 0 || n == 1) return false;
  else if (n == 2 || n == 3 || n == 5 || n == 7) return true;
  else if (n % 2 == 0 || n % 3 == 0) return false;
  else {
    for (ll i = 5; i * i <= n; i += 6)
      if (n % i == 0 || n % (i + 2) == 0)
	return false;
    return true;
  }
}
*/

boost::mt19937 gen2(clock());

bool isPrime(ll n){
return boost::multiprecision::miller_rabin_test(n,10,gen2);
}

int main(){

  ll res=0;
  for(ll i=10;i<=N;i+=10){
    ll n=i*i;
    if(n%3!=1) continue;
    if(n%7!=2 && n%7!=3) continue;   
    if(n%11!=0 && n%11!=1 && n%11!=3 && n%11!=5 && n%11!=7) continue;   
    if(isPrime(n+1) && isPrime(n+3) && isPrime(n+7) && isPrime(n+9) && isPrime(n+13) && isPrime(n+27) && !isPrime(n+19) && !isPrime(n+21))
      res += i;

  }

    cout << res << '\n';
}
