#include<iostream>
#include<gmpxx.h>

using namespace std;

mpq_class q=(0.5);

mpq_class f(int n){
  if(n==0) return 1;
  return 1+1/(1+f(n-1));
}

int count(mpz_class n){
  int res=0;
  while(n!=0){n/=10; ++res;}
  return res;
}

int main(){
  int res=0;
  for(int i=0;i<1001;++i){
    mpz_class num=f(i).get_num(), dem=f(i).get_den();
    if(count(num)>count(dem)) ++res;
  }

  cout << res << '\n';
}
