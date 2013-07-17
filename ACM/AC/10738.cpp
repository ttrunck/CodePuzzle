#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

const int N=1000001;

int main(){
  vector<bool> prime(N,true);
  prime[0]=prime[1]=false;
  for(int i=2;i<N;++i)
    if(prime[i])
      for(int j=i+i;j<N;j+=i)
	prime[j]=false;

  vector<int> mu(N,1);
  for(int i=2;i<N;++i)
    if(prime[i])
      for(int j=i;j<N;j+=i){
	if(j%(i*i)==0) mu[j]=0;
	mu[j]*=-1;
      }
  

  vector<int> M(N,0);
  for(int i=1;i<N;++i)
    M[i]=M[i-1]+mu[i];

  int n;
  while(cin >> n && n){
    cout << setfill(' ') << setw(8);
    cout << n;
	cout << setfill(' ') << setw(8);
    cout << mu[n];
cout << setfill(' ') << setw(8);
    cout << M[n];
    cout << '\n';
  }
}
