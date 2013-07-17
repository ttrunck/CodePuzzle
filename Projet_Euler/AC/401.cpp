#include<iostream>
#include<gmpxx.h>

using namespace std;

typedef mpz_class bint;

const long N=1000000000000000;
const long MOD=1000000000;

long next(long a){
  long lo=a,hi=N;
  while(lo!=hi){
    long x=(lo+hi)/2;
    if(N/(x+1)<N/a)
      hi=x;
    else
      lo=x+1;
  }
  return lo;
}

bint sum(bint aa, bint bb){
  --aa;
  bint a=aa;
  bint b=bb;
  bint tmp1=(((b*(b+1))%(6*MOD))*(2*b+1))%(6*MOD);
  bint tmp2=(((a*(a+1))%(6*MOD))*(2*a+1))%(6*MOD);
  tmp1/=6;
  tmp2/=6;
  return (tmp1-tmp2+2*MOD)%MOD;
}

int main(){
  long a=1,b;
  bint res=0;
  while(a<=N){
    b=next(a);
    //cerr << a << ' ' << b << ' ' << N/a << ' ' << N/b << endl;
    res=(res+(N/a)*sum(a,b))%MOD;
    a=b+1;
  }
  cout << res << endl;
}
