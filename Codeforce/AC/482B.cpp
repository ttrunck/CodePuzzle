#include <algorithm>
#include <array>
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

typedef long long ll;

class fenwick{
	vector<int> t;

	void incremente(int x, int inc) {
		while (x < int(t.size())) {
			t[x] += inc;
			x = x|(x+1);
		}
	}

 public:
 	fenwick(int n=0) {
 		t.assign(n, 0);
 	}

	int sum(int x, int y) const {
		if (x == 0) {
			int res=0;
			while (y >= 0) {
				res += t[y];
				y = (y&(y+1))-1;
			}
			return res;
		}
		else
			return sum(0,y)-sum(0,x-1);
	}

	void set(int x, int val) {
		int inc = val - sum(x, x);
		incremente(x, inc);
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;

	vector<vector<int>> t(32, vector<int>(n+1, 0));
	vector<vector<int>> constraint(m);
	for(int i=0;i<m;++i){
		int l, r, q;
		cin >> l >> r >> q;
		--l; --r;
		constraint[i] = {l, r, q};
		for(int j=0;j<32;++j){
			if(q%2==1){
				t[j][l] += 1;
				t[j][r+1] -= 1;
			}
			q/=2;
		}
	}

	vector<fenwick> f(32, fenwick(n));

	for(int i=0;i<32;++i){
		int curr = 0;
		for(int j=0;j<n;++j){
			curr += t[i][j];
			if(curr>0)
				f[i].set(j, 1);
		}
	}

	for(auto& arr : constraint) {
		int l = arr[0], r = arr[1], q = arr[2];
		for(int j=0;j<32;++j){
			if((q%2==1 && f[j].sum(l, r)!=r-l+1) 
				|| (q%2==0 && f[j].sum(l,r)==r-l+1)){
				cout << "NO\n";
				return 0;
			}
			q/=2;
		}
	}

	cout << "YES\n";
	for(int i=0;i<n;++i){
		int curr = 0;
		for(int j=0;j<32;++j)
			curr |= f[j].sum(i, i) << j;
		cout << curr << ' ';
	}

}