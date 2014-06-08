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

	int res = 1;
	int curr = 0;
	int i=0;
	while(i<n){
		while(i<n && curr + t[i]<=m){
			curr += t[i];
			++i;
		}
		if(i<n){
			++res;
			curr = 0;
		}
	}

	

	cout << res << '\n';
}