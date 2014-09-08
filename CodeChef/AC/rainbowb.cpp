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

typedef long long ll;

const int MOD = 1000000007;

int rain(int c, int n, vector<vector<int>>& mem){
	if(n<=0) return 0;
	if(c==0) return 1;

	if(mem[c][n]!=-1) return mem[c][n];

	int res = 0;
	res = (res+rain(c-1,n-2,mem) + rain(c, n-2, mem))%MOD;

	return mem[c][n] = res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<vector<int>> mem(7, vector<int>(n+1, -1));
	for(int i=0;i<n;++i)
		rain(6,i,mem);
	cout << rain(6,n,mem) << '\n';
}