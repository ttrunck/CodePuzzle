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

bool ispal(int deb, int fin, bool del, const string& s){
	if(deb>=fin)
		return true;
	if(s[deb]==s[fin] && ispal(deb+1, fin-1, del, s))
		return true;
	if(del && (ispal(deb+1, fin, false, s) || ispal(deb, fin-1, false, s)))
		return true;
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		if(ispal(0, s.size()-1, true, s))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}