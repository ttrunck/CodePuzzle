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
		ll n;
		cin >> n;
		ostringstream ss;
		ss << n;
		string s = ss.str();
		int res = 0;
		for(char c:s)
			if(c!='0' && n%(c-'0')==0)
				++res;
		cout << res << '\n';
	}
}