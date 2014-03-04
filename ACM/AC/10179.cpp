#include<iostream>

using namespace std;

int const N=100000009;
//int phi[N];

int phi(int n){
  int res=1;
  for(int i=2;i*i<=n;++i)
    if(n%i==0){
      while(n%i==0){
	res*=i;
	n/=i;
      }
      res=res/i*(i-1);
    }
  if(n!=1){
    res*=n-1;
  }
  return res;
}

int main(){
  /*
  for(int i=2;i<N;++i)
    phi[i]=i;
  
  for(int i=1;i<N;++i)
    if(phi[i]==i){
      for(int j=i;j<N;j+=i){
	phi[j]=phi[j]-phi[j]/i;
      }
    }
  */	
  int n;
  cin >> n;
  while(n!=0){
    cout << phi(n) << endl;
    cin >> n;
  }
}
