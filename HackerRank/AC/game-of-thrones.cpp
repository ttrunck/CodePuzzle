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
	string s;
	cin >> s;
	int bad = 0;

	vector<int> count(26, 0);
	for(char c:s)
		count[c-'a']++;

	for(int x:count)
		bad += x%2;

	if(bad>1)
		cout << "NO\n";
	else
		cout << "YES\n";
}