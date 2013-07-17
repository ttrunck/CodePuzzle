#include<iostream>
#include<vector>

using namespace std;

int const N=10000;
bool is_prime[N];
vector<int> prime;

int const S=50000001;
bool ok[S];

int main(){
 for(int i=0;i<N;++i)
    is_prime[i]=(i%2==1);
  is_prime[1]=false;
  is_prime[2]=true;
  for(int i=3;i<N;++i)
    if(is_prime[i])
      for(int j=i+i;j<N;j+=i)
	is_prime[j]=false;

  for(int i=0;i<N;++i)
    if(is_prime[i]) prime.push_back(i);

  for(int i=0;i<S;++i)
    ok[i]=false;

  for(int i=0;prime[i]*prime[i]<S;++i)
    for(int j=0;prime[i]*prime[i]+prime[j]*prime[j]*prime[j]<S;++j)
      for(int k=0;prime[i]*prime[i]+prime[j]*prime[j]*prime[j]+prime[k]*prime[k]*prime[k]*prime[k]<S;++k)
	ok[prime[i]*prime[i]+prime[j]*prime[j]*prime[j]+prime[k]*prime[k]*prime[k]*prime[k]]=true;
  
  int res=0;
  for(int i=0;i<S;++i)
    if(ok[i]) res++;
  cout << res << '\n';
     
 
}
