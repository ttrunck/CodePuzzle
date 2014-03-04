#include <iostream>
#include <gmpxx.h>
using namespace std;

typedef mpz_class ent;

int const N=100;

bool prime[N];

ent nb_div_square(ent n){
  ent nn=n;
  ent res=1;
  int p=2;
  while(nn!=1){
    while(!(prime[p] && nn%p==0)) {if(p>=N) return -1;++p;}
    int k=0;
    while(nn%p==0){nn/=p;k++;}
    res*=2*k+1;
  }
  return res;
}

int main(){

  for(int i=0;i<N;++i)
    prime[i]=(i%2==1);
  prime[1]=false;
  prime[2]=true;
  for(int i=3;i<N;++i)
    if(prime[i])
      for(int j=i+i;j<N;j+=i)
	prime[j]=false;
  int n=1;
  while((nb_div_square(n)+1)/2<1000) n++;
  cout << n << '\n';
}
