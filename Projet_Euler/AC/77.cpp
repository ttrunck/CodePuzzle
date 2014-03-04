#include<iostream>
#include<vector>

using namespace std;

int const N=5000;
int const C=5000;
bool is_prime[N];
vector<int> prime;
int res[N];

int main(){
  for(int i=0;i<N;++i)
    is_prime[i]=i%2==1;
  is_prime[1]=false;
  is_prime[2]=true;
  for(int i=3;i<N;++i)
    if(is_prime[i])
      for(int j=i+i;j<N;j+=i)
	is_prime[j]=false;

  for(int i=0;i<N;++i)
    if(is_prime[i])
      prime.push_back(i);

  for(int i=0;i<N;++i)
    res[i]=0;

  for(int i=0;i<prime.size();++i){
    int p=prime[i];
    res[p]++;
    for(int j=p;j<N;++j)
      res[j]+=res[j-p];
  }
    int i=0;
    while(i<N && res[i]<C){
      cout << i << ' ' << res[i] << '\n';
      ++i;
    }
    cout << i << '\n';
}
