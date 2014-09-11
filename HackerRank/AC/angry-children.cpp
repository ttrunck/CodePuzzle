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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<int> t(n);
	for(int i=0;i<n;++i)
		cin >> t[i];
	sort(begin(t), end(t));
	int res = t[n-1]-t[0];
	for(int i=0;i<=n-k;++i)
		res = min(res, t[i+k-1]-t[i]);

	cout << res << '\n';
}