#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <random>
#include <set>
#include <sstream>
#include <cassert>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	priority_queue<pi> q;
	map<int, int> period;
	while(getline(cin, s)){
		if(s[0]=='#') break;
		istringstream ss(s);
		string tmp;
		int x, p;
		ss >> tmp >> x >> p;
		period[x] = p;
		q.push(pi{-p, -x});
	}
	int k;
	cin >> k;
	while(k--){
		pi p = q.top();
		q.pop();
		cout << -p.second << '\n';
		q.push(pi{p.first-period[-p.second], p.second});
	}
}