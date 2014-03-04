#include<iostream>

using namespace std;

int const N=1000000;
int prime[N];

bool trunright(int n){
  while(n!=0){
    if(!prime[n]) return false;
    n/=10;
  }
  return true;
}

bool trunleft(int n){
  int tmp=10;
  while(n%tmp!=n){
    if(!prime[n%tmp]) return false;
    tmp*=10;
  }
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

  int curr=10;
  int nb=0;
  int res=0;
  while(nb!=11){
    if(trunleft(curr) && trunright(curr)){
      nb++;
      res+=curr;
      cout << curr << '\n';;
    }
    curr++;
  }
  cout << res << '\n';
}
