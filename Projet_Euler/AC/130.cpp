#include<iostream>
#include<gmpxx.h>

using namespace std;

typedef mpz_class bint;

int N=10000000;

int main(){

  vector<bool> prime(N,true);
  prime[0]=false;
  prime[1]=false;
  for(int i=2;i<N;++i)
    if(prime[i])
      for(int j=i+i;j<N;j+=i)
	prime[j]=false;

  int res=0;
  int comp=25;
  int n=1;
  while(comp && ++n){
    if(n%2==0 || n%5==0 || prime[n]) continue;
    bint r=1;
    int k=1;
    while(r%n!=0){
      k++;
      r=10*r+1;
    }

    if((n-1)%k==0){
      comp--;
      res+=n;
      cerr << n << endl;
    }
  }
  cout << res << endl;
}
