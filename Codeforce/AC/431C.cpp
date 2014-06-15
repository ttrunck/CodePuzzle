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

int aux(int ok, int n, int k, int d,  vector<vector<int>>& mem){
	if(n==0) return ok;

	if(mem[ok][n] != -1) return mem[ok][n];

	ll res=0;
	for(int i=1;i<=min(n,k);++i)
		if(i<d)
			res+=aux(ok, n-i, k, d, mem);
		else
			res+=aux(1, n-i, k, d, mem);

	return mem[ok][n] = res%MOD;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k, d;
	cin >> n >> k >> d;

	vector<vector<int>> mem(2, vector<int>(n+1, -1));

	cout << aux(0, n, k, d, mem) << '\n';
}