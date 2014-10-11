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
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		vector<int> t(n);
		for(int i=0;i<n;++i)
			cin >> t[i];
		ll res = 0;
		ll curr = t[0];
		for(int i=1;i<n;++i){
			res += abs(curr);
			curr += t[i];
		}
		cout << res << '\n';	
	}
}