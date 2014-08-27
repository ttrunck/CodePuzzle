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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	while(cin >> n && n){
		map<vector<int>, int> m;
		for(int i=0;i<n;++i){
			vector<int> t(5);
			for(int j=0;j<5;++j)
				cin >> t[j];
			sort(begin(t), end(t));
			++m[t];
		}

		int maxi = -1;
		for(auto p:m)
			maxi = max(maxi, p.second);

		int res = 0;
		for(auto p:m)
			if(p.second == maxi)
				res += maxi;
		cout << res << '\n';
	}
}