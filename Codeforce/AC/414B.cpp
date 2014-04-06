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

const int MOD = 1000000007;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k;
	cin >> n >> k;
	vector<vector<int>> mem(k+1, vector<int>(n+1, 0));
	for(int i=1;i<=n;++i)
		mem[1][i] = 1;
	for(int i = 2;i<=k;++i)
		for(int j=1;j<=n;++j)
			for(int k=j;k<=n;k+=j)
				mem[i][j] = (mem[i][j] + mem[i-1][k]) % MOD;

	int res = 0;
	for(int i=1;i<=n;++i)
		res = (res + mem[k][i])% MOD;
	cout << res << endl;

}