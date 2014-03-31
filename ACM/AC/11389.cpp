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
	int n, d, r;
	while(cin >> n >> d >> r && (n || d || r)){
		vector<int> t1(n), t2(n);
		for(int i=0;i<n;++i)
			cin >> t1[i];
		for(int i=0;i<n;++i)
			cin >> t2[i];
		sort(begin(t1), end(t1));
		sort(begin(t2), end(t2));

		int res= 0;
		for(int i=0;i<n;++i)
			res += r * max(0,t1[i]+t2[n-1-i]-d);
		cout << res << '\n';
	}
}