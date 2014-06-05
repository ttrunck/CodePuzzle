#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <random>
#include <set>
#include <sstream>
#include <cassert>

using namespace std;

typedef long long ll;

struct box{
	int pos;
	int k;
	ll v;
	bool u;

	bool operator< (const box& b) const{
		return v>b.v;
	}

	box(int kk, ll q, int p):pos(p), k(kk), u(false){
		v = q;
		for(int i=0;i<kk;++i)
			v*=10;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll x, n;
	while(cin >> x >> n){
		vector<box> t;
		for(ll i=0;i<n;++i){
			ll k;
			ll q;
			cin >> k >> q;
			t.push_back(box(k, q, i+1));
		}
		sort(begin(t), end(t));
		int used = 0;
		ll lim = x;

		for(ll w = 1, k=0;k<19;++k, w*=10){
			lim = lim/(w*10) * (w*10);
			if(x<=lim) continue;
			for(auto& b:t)
				if(!b.u && b.k<=k){
					b.u = true;
					x -= b.v;
					++used;
					if(x<=lim)
						break;
				}
			if(x>lim){	
				used=0;
				break;
			}
		}
		if(used == 0)
			cout << "-1\n";
		else{
			cout << used << '\n';
			bool first = true;
			for(auto& b:t)
				if(b.u){
					if(!first)
						cout << ' ';
					first = false;
					cout << b.pos;
				}
			cout << '\n';
		}
	}
}