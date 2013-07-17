#include<iostream>

using namespace std;

int const N=50009;
int phi[N];

int main(){
  for(int i=2;i<N;++i)
    phi[i]=i;
  
  for(int i=1;i<N;++i)
    if(phi[i]==i){
      for(int j=i;j<N;j+=i){
	phi[j]=phi[j]-phi[j]/i;
      }
    }
	
  int n;
  cin >> n;
  while(n!=0){
    int res=0;
    for(int i=2;i<=n;++i)
      res+=phi[i];
    res*=2;
    res++;
    cout << res << endl;
    cin >> n;
  }
}
