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

  /* for (int i=0;i<100;++i)
    cout << i << ':' << prime[i] << ' ';
  */
  int curr=0;
  int pos=0;
  while (curr!=10001){
    pos++;
    if (prime[pos]) curr++;
  }
  cout << pos;
}
