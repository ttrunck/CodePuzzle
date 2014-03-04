#include<iostream>

using namespace std;

int const N=7654322;
bool prime[N];

bool panta(int x,int nn){
  int xx=x;
  bool t[nn];
  for(int i=0;i<nn;++i)
    t[i]=0;
  while(xx!=0){
    int tmp=xx%10;
    if(tmp==0) return false;
    tmp--;
    if(t[tmp]) return false;
    t[tmp]=true;
    xx/=10;
  }
  for(int i=0;i<nn;++i)
    if(!t[i]) return false;
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

  cout << "Initialisation terminée\n";
  for(int nn=4;nn<8;++nn)
    for(int i=2;i<N;++i)
      if(prime[i] && panta(i,nn))
	cout << i << '\n';;
  /*rem: 8-panta et 9-panta sont divisible par 3*/
}
