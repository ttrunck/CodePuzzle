#include<iostream>

using namespace std;

typedef long long ll;

bool is2(ll a){
  return (a&(a-1))==0;
}

int main(){
  double perfect=1;
  ll p;
  for(p=3;perfect/(p-1)>=1./12345.;++p){
    if(is2(p))
      ++perfect;
  }
  cout << p*p-p << '\n';
}
