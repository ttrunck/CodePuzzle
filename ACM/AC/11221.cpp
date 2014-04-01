#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <random>
#include <set>
#include <sstream>
#include <cassert>
#include <cmath>

using namespace std;

typedef long long ll;

bool is_pal(const string& s, int n){
	for(int i=0;i<n*n;++i)
		if(s[i] != s[n*n-1-i])
			return false;

	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			if(s[n*i+j] != s[i+j*n] || s[n*i+j] != s[n*(n-1-j)+n-1-i])
				return false;

	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int nbcase;
	cin >> nbcase;
	cin.ignore();
	for(int icase = 1;icase<=nbcase;++icase){
		cout << "Case #" << icase << ":\n";
		string s;
		getline(cin, s);
		string ss;
		for(char c:s)
			if(isalpha(c))
				ss+=c;
		int n = sqrt(ss.size());
		if(n*n!=int(ss.size()) || !is_pal(ss, n))
			cout << "No magic :(\n";
		else
			cout << n << '\n';
		//cerr << ss << endl;
	}
}