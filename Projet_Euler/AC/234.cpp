#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

typedef long long ll;

const int N=10000000;
const ll L=999966663333;
//const int L=1000;

inline ll sum(ll a, ll b){
  return b*(a/b*(a/b+1))/2;
}

ll add(ll a, ll b, ll c, ll d){
  ll res=0;
  res -= sum(a-1,c);
  res -= sum(a-1,d);
  res += sum(b,c);
  res += sum(b,d);

  if(c*d<=b)
    res-=2*c*d;
  return res;
}

int main(){
  vector<bool> prime(N,true);
  prime[0]=false;
  prime[1]=false;

  for(int i=2;i<N;++i)
    if(prime[i])
      for(int j=i+i;j<N;j+=i)
	prime[j]=false;

  vector<ll> p;
  for(int i=2;i<N;++i)
    if(prime[i])
      p.push_back(i);


  ll res = 0;
  for(int i=1;i<int(p.size());++i){
    assert(p[i-1]!=0);
    assert(p[i]!=0);
    if(p[i]*p[i]>L){
      res+=add(p[i-1]*p[i-1]+1, L, p[i-1], p[i]);
      break;
    }
    else
      res+=add(p[i-1]*p[i-1]+1, p[i]*p[i]-1, p[i-1], p[i]);
  }


  cout << res << '\n';
}
