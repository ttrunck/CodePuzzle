#include<iostream>
#include<gmpxx.h>

typedef mpz_class ent;

using namespace std;

ent const N=10000000000;

int const P=10000000;
bool prime[P];

ent calc(ent p, int n){
  if(n%2==0) return 2;
  else return (2*n*p);
}

int main(){
  for(int i=0;i<P;++i)
    prime[i]= (i%2==1);
  prime[1]=false;
  prime[2]=true;
  for(int i=3;i<P;++i)
    if(prime[i])
      for(int j=i+i;j<P;j+=i)
	prime[j]=false;
  int n=0;
  for(int i=0;i<P;++i)
    if(prime[i]){
      n++;
      if(calc(i,n)>N){
	cout << n << '\n';
	break;
      }
    }
}
