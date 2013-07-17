#include<iostream>
#include<cmath>
using namespace std;

int const N=10000000;
double const ratio=0.1; 
bool prime[N];

bool primef(int n){
  //  cout << n << '\n';
  if(n<N) return prime[n];
  for(int i=2;i<sqrt(n)+1;++i)
    if(n%i==0) return false;
  return true;
}

int main(){
  for(int i=0;i<N;++i)
    prime[i]=(i%2==1);
  prime[1]=false;
  prime[2]=true;
  for(int i=3;i<N;++i)
    for(int j=i+i;j<N;j+=i)
      prime[j]=false;

  int si=2;
  int curr=1;
  int nb=1;
  int p=0;
  while(nb<3 || (double)p/(double)nb>ratio){
    for(int j=0;j<4;++j){
      nb++;
      curr+=si;
      if(primef(curr)) p++;
    }
    si+=2;
  }
  cout << si-1 << '\n';
}
