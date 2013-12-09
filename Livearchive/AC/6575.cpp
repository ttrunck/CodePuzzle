#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

vector<ll> t;

ll cmp(ll n, bool flag){
  ll curr5=5;
  ll po=1;
  while(n/curr5!=0){
    curr5*=5;
    ++po;
  }
  --po;
  curr5/=5;
  if(po!=0){
    if(flag)
      return t[po-1] + cmp(n-curr5, (po%2)?!flag:flag);
    else
      return curr5-t[po-1] + cmp(n-curr5, (po%2)?!flag:flag);
  }
  else if(flag)
    return n+1;
  else
    return 0;
}

int main(){
  t.push_back(5);
  t.push_back(15);
  t.push_back(75);
  for(int i=0;i<50;++i)
    t.push_back(-25*t[i]+5*t[i+1]+5*t[i+2]);

  ll n;
  while(cin >> n && n!=-1)
    cout << cmp(n,true) << '\n';
}
