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
	ll n, m;
	cin >> n >> m;
	ll res = 0;
	for(int i=0;i<m;++i){
		ll a, b, k;
		cin >> a >> b >> k;
		res += (b-a+1)*k;
	}
	cout << res/n << '\n';
}