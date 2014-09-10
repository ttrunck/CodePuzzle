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
	int n;
	cin >> n;
	vector<int> t(26, 0);
	for(int i=0;i<n;++i){
		string s;
		cin >> s;
		vector<bool> tmp(26, false);
		for(char c:s)
			tmp[c-'a'] = true;
		for(int i=0;i<26;++i)
			if(tmp[i])
				t[i]++;
	}
	int res = 0;
	for(int x:t)
		if(x==n)
			++res;
	cout << res << '\n';
}