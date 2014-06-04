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

void transform(const string& s, vector<pair<char, int>>& t) {
	char curr = s[0];
	int nb = 1;
	for(int i=1;i<int(s.size());++i){
		if(s[i]==curr)
			++nb;
		else{
			t.push_back(make_pair(curr, nb));
			curr = s[i];
			nb = 1;
		}
	}
	t.push_back(make_pair(curr, nb));
}

bool impossible(const vector<vector<pair<char, int>>>& t) {
	for(int i=1;i<int(t.size());++i){
		if(t[0].size()!=t[i].size())
			return true;
		for(int j=0;j<int(t[0].size());++j)
			if(t[0][j].first != t[i][j].first)
				return true;
	}

	return false;
}

int solve(const vector<vector<pair<char, int>>>& t) {
	int res = 0;
	for(int i=0;i<int(t[0].size());++i){
		vector<int> m(t.size());
		for(int j=0;j<int(t.size());++j)
			m[j] = t[j][i].second;
		sort(begin(m), end(m));
		int cible = m[m.size()/2];
		for(int x:m)
			res += abs(x-cible);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	for(int icase = 1;icase<=T;++icase){
		cout << "Case #" << icase << ": ";
		int n;
		cin >> n;
		vector<string> tt(n);
		vector<vector<pair<char, int>>> t(n);
		for(int i=0;i<n;++i){
			cin >> tt[i];
			transform(tt[i], t[i]);
		}

		if(impossible(t))
			cout << "Fegla Won\n";
		else{
			cout << solve(t) << '\n';
		}
	}
}