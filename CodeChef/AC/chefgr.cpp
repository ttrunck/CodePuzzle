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
		int n, m;
		cin >> n >> m;
		vector<int> t(n);
		for(int i=0;i<n;++i)
			cin >> t[i];
		int maxi = t[0];
		for(int x:t)
			maxi = max(maxi, x);
		for(int x:t)
			m-=(maxi-x);
		if(m<0 || m%n!=0)
			cout << "No\n";
		else
			cout << "Yes\n";

	}
}