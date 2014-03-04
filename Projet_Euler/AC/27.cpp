#include <iostream>
#include <cmath>

using namespace std;

int const N=5000000;
int const M=1000;
bool prime[N];

void init(){
  for(int i=0;i<N;++i)
    prime[i]=(i%2!=0);
  prime[0]=false;
  prime[2]=true;

  for(int i=3;i<N;++i)
    if(prime[i])
      for(int j=i+i;j<N;j+=i)
	prime[j]=false;
}

int count(int a, int b){
  int res=0;
  while(prime[res*res+a*res+b>0?res*res+a*res+b:-(res*res+a*res+b)])++res;
  return res;
}

int main(){
  int maxi=0, aa,bb;
  init();
  cout << "paf\n";
  for(int a=-M;a<=M;++a)
    for(int b=-M;b<=M;++b){
      int tmp=count(a,b);
      if(tmp>maxi){
	maxi=tmp;
	aa=a;
	bb=b;
      }
    }
  cout << aa << ' ' << bb << '\n';
  cout << aa*bb << '\n';
}
