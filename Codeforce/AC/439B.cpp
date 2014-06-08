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
	ll n, x;
	cin >> n >> x;
	vector<ll> t(n);
	for(int i=0;i<n;++i)
		cin >> t[i];
	sort(begin(t), end(t));
	ll res = 0;
	for(int i=0;i<n;++i)
		res += max(1ll,(x-i))*t[i];
	cout << res << '\n';
}