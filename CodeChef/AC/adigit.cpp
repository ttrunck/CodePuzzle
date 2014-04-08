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
	
	int n, m;
	cin >> n >> m;
	vector<int> data(n);
	vector<vector<int>> t(n, vector<int>(10, 0));
	char c;
	cin >> c;
	t[0][c-'0'] = 1;
	data[0] = c-'0';
	for(int i=1;i<n;++i){
		for(int j=0;j<10;++j)
			t[i][j] = t[i-1][j];
		cin >> c;
		t[i][c-'0'] += 1;
		data[i] = c-'0';
	}

	// for(auto x:data)
	// 	cerr << x << ' ';
	// cerr << endl;

	// for(auto& tt:t){
	// 	for(auto x:tt)
	// 		cerr << x << ' ';
	// 	cerr << endl;
	// }

	for(int i=0;i<m;++i){
		int x;
		cin >> x;
		--x;

		int res = 0;
		for(int i=0;i<data[x];++i)
			res += t[x][i]*(data[x]-i);
		for(int i=data[x]+1;i<10;++i)
			res += t[x][i]*(i-data[x]);

		cout << res << '\n';
	}
}