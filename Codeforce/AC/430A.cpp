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
typedef pair<int, int> pii;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<pii> t(n);
	for(int i=0;i<n;++i){
		cin >> t[i].first;
		t[i].second = i;
	}
	sort(begin(t), end(t));
	vector<int> res(n, 0);
	for(int i=0;i<n;i+=2)
		res[t[i].second] = 1;
	for(auto x:res)
		cout << x << ' ';
	cout << '\n';
}