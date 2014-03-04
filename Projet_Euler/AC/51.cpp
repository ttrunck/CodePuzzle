#include<iostream>

using namespace std;

int const N=10000000;
bool prime[N];

int const NN=8;
int const S=7;

int number[S];
int tmp[S];

void copie(){
  for(int i=0;i<S;++i)
    tmp[i]=number[i];
}

bool paf(){
  for(int i=0;i<S;++i){
    if(number[i]==0) continue;
    if(number[i]==10) return false;
    else return true;
  }
  return false;
}

bool check(){
  int res=0;
    int n=0;  
    copie();
    for(int i=(paf()?0:1);i<10;++i){
      for(int j=0;j<S;++j)
	if(tmp[j]==10) tmp[j]=i;
    
    for(int j=0;j<S;++j)
      n=10*n+tmp[j];
    
    if(prime[n]) res++;
    copie();
    n=0;
  }
  return (res==NN);
}

void plus_un(){
  number[S-1]++;
  for(int i=S-1;i>0;--i)
    if(number[i]>10){
      number[i]=0;
      number[i-1]++;
    }
}

int main(){
  for(int i=0;i<N;++i)
    prime[i]=(i%2==1);
  prime[1]=false;
  prime[2]=true;
  for(int i=3;i<N;++i)
    if(prime[i])
      for(int j=i+i;j<N;j+=i)
	prime[j]=false;

  for(int i=0;i<S;++i)
    number[i]=0;

  for(int i=0;i<N;++i){
    if(check()){
      for(int i=0;i<S;++i)
	cout << number[i] << ' ';
      cout << '\n';
    }
    plus_un();
  }
}
