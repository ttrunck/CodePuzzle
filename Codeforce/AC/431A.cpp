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
	vector<int> a(4);
	for(int i=0;i<4;++i)
		cin >> a[i];
	string s;
	cin >> s;
	int res = 0;
	for(char c:s)
		res += a[c-'1'];
	cout << res << '\n';
}