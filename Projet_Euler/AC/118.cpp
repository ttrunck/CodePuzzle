#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int const P=10000000;
bool prime[P];
int res=0;

int const taille=9;
int t[]={1,2,3,4,5,6,7,8,9};

bool fprime(int n){
  if(n<P) return prime[n];
  for(int i=2;i<=sqrt(n);++i)
    if(n%i==0) return false;
  return true;
}

void aux(int n, int mini){
  int tmp=t[n];
  for(int i=n+1;i<taille;++i){
    if(fprime(tmp) && tmp>mini)
      aux(i, tmp);
    tmp=tmp*10+t[i];
  }
  if(fprime(tmp) && tmp>mini) res++;
  return;
}

int main(){
  for(int i=0;i<P;++i)
    prime[i]=(i%2==1);
  prime[1]=false;
  prime[2]=true;
  for(int i=3;i<P;++i)
    if(prime[i])
      for(int j=i+i;j<P;j+=i)
	prime[j]=false;

  cout << "Initialisation done\n";

  do{
    aux(0,0);
  }while(next_permutation(t,t+taille));

  cout << res << '\n';
}
