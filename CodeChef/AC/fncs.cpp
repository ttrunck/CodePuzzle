#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef unsigned long long ll;
typedef pair<int, int> pi;

template<typename T>
class fenwick{
	vector<T> t;
	vector<T> data;

	void incremente(int x, T inc) {
		while (x < int(t.size())) {
			t[x] += inc;
			x = x|(x+1);
		}
	}

 public:
 	fenwick(int n) {
 		t.assign(n, 0);
 		data.assign(n, 0);
 	}

	T sum(int x, int y) const {
		if (x == 0) {
			T res=0;
			while (y >= 0) {
				res += t[y];
				y = (y&(y+1))-1;
			}
			return res;
		}
		else
			return sum(0,y)-sum(0,x-1);
	}

	T get(int x) const {
		return data[x];
	}

	void set(int x, T val) {
		T inc = val - data[x];
		incremente(x, inc);
		data[x] = val;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	fenwick<ll> t(n);
	for(int i=0;i<n;++i){
		ll tmp;
		cin >> tmp;
		t.set(i, tmp);
	}

	vector<pi> f(n);
	for(int i=0;i<n;++i){
		cin >> f[i].first >> f[i].second;
		--f[i].first;
		--f[i].second;
	}

	int sq = sqrt(n);
	vector<ll> sqt(n/sq + (n/sq*sq<n?1:0), 0);
	for(int i=0;i<n;++i)
		sqt[i/sq] += t.sum(f[i].first, f[i].second);

	vector<vector<int>> appear(n+1, vector<int>(sqt.size(), 0));
	for(int i=0;i<n;++i){
		appear[f[i].first][i/sq] += 1;
		appear[f[i].second + 1][i/sq] -= 1;
	}

	for(int i=1;i<n;++i)
		for(int j=0;j<int(sqt.size());++j)
			appear[i][j] += appear[i-1][j];

	int q;
	cin >> q;
	for(int i=0;i<q;++i){
		int type, x, y;
		cin >> type >> x >> y;
		if(type == 1){
			--x;
			for(int j=0;j<int(sqt.size());++j)
				sqt[j] += ll{appear[x][j]} * (ll{y} - t.get(x));
			t.set(x, y);
		}
		else{
			--x;--y;
			ll res = 0;
			for(int j=0;j<int(sqt.size());++j){
				int deb = j*sq;
				int fin = min(n-1, deb + sq - 1);
				if(x<=deb && y>=fin)
					res += sqt[j];
				else{
					for(int k = max(deb, x); k<=min(fin, y); ++k)
						res += t.sum(f[k].first, f[k].second);
				}
			}
			cout << res << '\n';
		}
	}

}