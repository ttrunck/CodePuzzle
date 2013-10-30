#include<iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/miller_rabin.hpp>

using namespace std;

typedef long long ll;

boost::mt19937 gen2(clock());

bool isPrime(ll n){
return boost::multiprecision::miller_rabin_test(n,10,gen2);
}

const ll N=50000000;

int main(){
  int res=0;

  for(ll i=1;i<=N;++i)
    if(isPrime(2*i*i-1))
      res++;

  cout << res << '\n';
}
