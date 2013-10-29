#include<iostream>
#include<vector>

using namespace std;



typedef long long ll;

const ll N=2000*2000;

ll aux(int x, int y, int dx, int dy, const vector<ll>& t){
  ll res=0;
  ll curr=0;
  ll k=0;
  while((x+k*dx)<2000 && (x+k*dx)>=0 && y+k*dy<2000 && y+k*dy>=0){
    curr=max(0LL, curr+t[2000*(x+k*dx)+y+k*dy]);
    res=max(res, curr);
    ++k;
  }
  return res;
}

int main(){
  vector<ll> t(N);

  for(ll i=1;i<=55;++i)
    t[i-1]=(100003-200003*i+300007*i*i*i)%1000000-500000;
  for(ll i=55;i<N;++i)
    t[i]=(t[i-24]+t[i-55]+1000000)%1000000-500000;

  ll res=0;

  for(int i=0;i<2000;++i)
    res=max(res, aux(0,i,1,0,t));
  
  for(int i=0;i<2000;++i)
    res=max(res, aux(i,0,0,1,t));
  
  for(int i=0;i<2000;++i)
    res=max(res, aux(i,0,1,1,t));
  for(int i=0;i<2000;++i)
    res=max(res, aux(0,i,1,1,t));

  for(int i=0;i<2000;++i)
    res=max(res, aux(i,1999,1,-1,t));
  for(int i=0;i<2000;++i)
    res=max(res, aux(0,i,1,-1,t));
  
  cout << res << '\n';
}
