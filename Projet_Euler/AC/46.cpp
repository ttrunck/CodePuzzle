#include<iostream>

using namespace std;

int const N=100000;

bool prime[N];
bool conj[N];

int main(){
  for(int i=0;i<N;++i)
    prime[i]=(i%2==1);
  prime[1]=false;
  prime[2]=true;
  for(int i=3;i<N;++i)
    for(int j=i+i;j<N;j+=i)
      prime[j]=false;

  for(int i=0;i<N;++i)
    conj[i]=false;
  for(int i=2;i<N;++i){
    if(prime[i])
    for(int j=0;i+2*j*j<N;++j)
      conj[i+2*j*j]=true;
      }

      int res=3;
  while(conj[res]) res+=2;
  cout << res << '\n';
}
