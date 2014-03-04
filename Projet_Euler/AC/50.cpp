#include<iostream>
#include<vector>
using namespace std;

int const N=1000000;
bool prime[N];
vector<int> p;

int main(){
  for(int i=0;i<N;++i)
    prime[i]=(i%2==1);
  prime[1]=false;
  prime[2]=true;
  for(int i=3;i<N;++i)
    for(int j=i+i;j<N;j+=i)
      prime[j]=false;

  for(int i=0;i<N;++i)
    if(prime[i]) p.push_back(i);

  for(int i=2;i<N;++i){
    for(int j=0;j+i<p.size() && i*j<N;++j){
      int tmp=0;
      for(int k=0;k<i;++k){
	tmp+=p[j+k];
	if(tmp>N) break;
      }
      if (tmp<N && prime[tmp])
	cout << i << ' ' << tmp << '\n';
    }
  }
}
