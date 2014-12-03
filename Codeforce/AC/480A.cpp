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
typedef pair<int, int> pi;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<pi> t(n);
	for(int i=0;i<n;++i)
		cin >> t[i].first >> t[i].second;

	sort(begin(t), end(t));

	int res = 0;
	for(pi& p : t)
		res = (res>p.second)?p.first:p.second;

	cout << res << '\n';
}
