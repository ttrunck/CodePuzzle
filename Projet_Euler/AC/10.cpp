#include <iostream>

using namespace std;

const int N=2100000;

bool prime[N];

int main(){

  for (int i=0;i<N;++i)
    prime[i]=i%2!=0;
  prime[1]=false;
  prime[2]=true;
  for (int i=3;i<N;++i)
    if (prime[i])
      for(int j=i+i;j<N;j+=i)
	prime[j]=false;

  long long res=0;
  for(int i=0;i<2000000;++i)
    if (prime[i]) res+= i;
  
  cout << res;
}
