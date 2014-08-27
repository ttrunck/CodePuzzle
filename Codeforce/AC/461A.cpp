#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll n;
	cin >> n;
	vector<ll> t(n);
	for(int i=0;i<n;++i)
		cin >> t[i];

	sort(begin(t), end(t));

	ll res = n*t[n-1];
	for(ll i=0;i<n-1;++i)
		res += (i+2)*t[i];

	cout << res << '\n';
}