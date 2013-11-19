#include<iostream>
#include<vector>
#include<string>

using namespace std;

typedef long long ll;

int main(){
  ll a;
  cin >> a;
  string s;
  cin >> s;
  vector<ll> t(s.size());
  for(ll i=0;i<ll(s.size());++i)
    t[i]=s[i]-'0';

  vector<ll> psum(t.size()+1);
  for(int i=0;i<int(t.size());++i)
    psum[i+1]=psum[i]+t[i];

  vector<ll> count(t.size()*9+1);
  for(int i=0;i<int(t.size());++i)
    for(int j=i;j<int(t.size());++j)
      count[psum[j+1]-psum[i]]++;

  ll res=0;
  if(a!=0){
    for(ll d=1;d*d<=a;++d)
      if(a%d==0 && d<int(count.size()) && a/d<int(count.size()))
	res+=((d*d==a)?1:2)*count[d]*count[a/d];
  }
  else{
    res-=count[0];
    for(int x:count)
      res+=2*x;
    res*=count[0];
  }

  cout << res << '\n';
}
