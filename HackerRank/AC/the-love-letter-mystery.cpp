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
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int res = 0;
		for(int i=0;2*i<int(s.size());++i)
			res += abs(s[i]-s[int(s.size())-1-i]);
		
		cout << res << '\n';
	}
}