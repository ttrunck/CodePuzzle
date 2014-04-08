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

const int MOD = 1000000009;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--){
		int n, q;
		cin >> n >> q;
		vector<int> t(n);
		for(int i=0;i<n;++i)
			cin >> t[i];

		for(int query=0;query<q;++query){
			int m;
			cin >> m;
			vector<int> mem(m, 0);
			vector<int> tmp(m);
			mem[0]++;
			mem[(t[0]%m+m)%m]++;
			for(int i=1;i<n;++i){
				int tt = ((t[i]%m)+m)%m;
				for(int j=0;j<tt;++j)
					tmp[j] = (mem[j] + mem[j-tt+m]);
				for(int j=tt;j<m;++j)
					tmp[j] = (mem[j] + mem[j-tt]);

			for(int i=0;i<m;++i)
				mem[i] = tmp[i] % MOD;
			}
			cout << mem[0] << '\n';
			
		}
	}
}