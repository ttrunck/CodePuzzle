#include<iostream>
#include<gmpxx.h>

typedef mpq_class f;
typedef mpz_class ent;

using namespace std;

int const N=100;

f nb(int n){
  if(n%3==0) return 1;
  if(n%3==2) return 1;
  return ((n+2)/3)*2;
}

f calc(int n){
  if(n==N-1) return 0;
  f tmp=nb(n)+calc(n+1);
  return 1/tmp;
}



int main(){

  f tmp=2+calc(0);
  ent p=tmp.get_num();
  ent res=0;
  while(p!=0){
    res+=(p%10);
    p/=10;
  }
  cout << res << '\n';
}
