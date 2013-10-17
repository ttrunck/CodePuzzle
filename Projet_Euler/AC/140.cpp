#include<iostream>
#include<vector>

//genrating function and then
//use http://www.alpertron.com.ar/QUAD.HTM for the magic !

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int main(){
  vector<pi> start{pi(0,-1), pi(0,1), pi(-3,-2), pi(-3,2), pi(-4,-5), pi(-4,5), pi(2,-7), pi(2,-7)};
  vector<ll> good;

  for(auto p: start){
    ll x=p.first, y=p.second;
    for(ll i=0;i<30;++i){
      if(x>0)
	good.push_back(x);

      ll nx=-9*x-4*y-14;
      ll ny=-20*x-9*y-28;
      
      x=nx;
      y=ny;

    }
  }
  sort(begin(good), end(good));
  good.resize(distance(begin(good), unique(begin(good), end(good))));

  ll res=0;
  for(int i=0;i<30;++i)
    res+=good[i];

  cout << res << endl;  

}
