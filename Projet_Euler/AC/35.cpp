#include<iostream>

using namespace std;

int const N=1000000;
bool prime[N];

bool circular_prime(int i){
  if(!prime[i]) return false;
  int l=1,k=0;
  while(l*10<i){l*=10;k++;}
  for(int j=0;j<k;++j){
    int tmp=i%10;
    i/=10;
    i+=tmp*l;
    if(!prime[i]) return false;
  }
  return true;
}

int main(){
  for(int i=0;i<N;++i)
    prime[i]=(i%2!=0);
  prime[1]=false;
  prime[2]=true;
  for(int i=3;i<N;++i)
    for(int j=i+i;j<N;j+=i)
      prime[j]=false;
  int res=0;
  for(int i=2;i<N;++i)
    if(circular_prime(i)){cout << i << '\n'; res++;}
  cout << res << '\n';
}
