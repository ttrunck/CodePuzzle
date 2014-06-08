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
	int n, k;
	cin >> n >> k;
	vector<int> t(n);
	for(int i=0;i<n;++i)
		cin >> t[i];
	int ok=0;
	for(int x:t)
		if(x+k<=5)
			++ok;
	cout << ok/3 << '\n';
}