#include<iostream>
#include<vector>

//genrating function and then
//use http://www.alpertron.com.ar/QUAD.HTM for the magic !

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

int main(){
  vector<pi> start{pi(0,-1), pi(0,1), pi(-1,-2), pi(-1,2), pi(2,-5)};
  vector<ll> good;

  for(auto p: start){
    ll x=p.first, y=p.second;
    for(ll i=0;i<20;++i){
      if(x>0)
	good.push_back(x);

      ll nx=-9*x-4*y-2;
      ll ny=-20*x-9*y-4;
      
      x=nx;
      y=ny;

    }
  }
  sort(begin(good), end(good));
  good.resize(distance(begin(good), unique(begin(good), end(good))));

  cout << good[15-1] << endl;  

}
