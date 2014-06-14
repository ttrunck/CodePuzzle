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
	vector<int> t(n);
	for(int i=0;i<n;++i)
		cin >> t[i];
	int res = 0;
	for(int i=0;i<m;++i){
		int a, b;
		cin >> a >> b;
		res += min(t[a-1], t[b-1]);
	}
	cout << res << '\n';
}