#include<iostream>
#include<vector>
using namespace std;

typedef long long ent;

int const N=1000000;
int const P=N;

bool is_prime[P];
vector<int> prime;

ent f(ent n){
  return n*(n-1)/2;
}

ent inclusionexclusion(ent limit, ent index){
  ent count=f(limit);
  while(index<prime.size() && prime[index]<=limit){
    ent newlimit=limit/prime[index];
    count-= inclusionexclusion(newlimit, index+1);
    index++;
  }
  return count;
}

int main(){
  for(int i=0;i<P;++i)
    is_prime[i]=(i%2==1);
  is_prime[1]=false;
  is_prime[2]=true;
  for(int i=3;i<P;++i)
    if(is_prime[i])
      for(int j=i+i;j<P;j+=i)
	is_prime[j]=false;

  for(int i=0;i<P;++i)
    if(is_prime[i]) prime.push_back(i);

  cout << inclusionexclusion(N,0) << '\n';
  /*
  int res=2;
  for(int d=1;d<=N;++d)
    for(int j=1;j<d;++j)
      if(reduced(j,d)) ++res;
  cout << res << '\n';
  */
}
