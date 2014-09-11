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
	int l, r;
	cin >> l >> r;
	int res = 0;
	for(int i=l;i<=r;++i)
		for(int j=l;j<=r;++j)
			res = max(res, i^j);
	cout << res << '\n';
}