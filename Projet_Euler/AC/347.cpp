#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

const int N=10000000;

ll maxi(ll p, ll q){
  ll res=0;
  ll curr=p*q;
  if(curr>N)
    return 0;
  while(curr*p<=N)curr*=p;
  res=max(res, curr);
  while((curr/p)%p==0){
    curr/=p;
    while(curr*q<=N)curr*=q;
    res=max(res, curr);
  }

  return res;
}

int main(){
  vector<vector<int> > t(N+1);
  for(int i=2;i<=N;++i)
    if(int(t[i].size())==0)
      for(int j=i;j<=N;j+=i)
	if(int(t[j].size())<3)
	  t[j].push_back(i);

  ll res=0;  
  for(int i=0;i<=N;++i)
    if(int(t[i].size())==2){
      if(i==maxi(t[i][0],t[i][1]))
	res+=i;
    }
 
  cout << res << '\n';
}
