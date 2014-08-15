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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	while(cin >> n && n){
		priority_queue<int, vector<int>, greater<int>> q;
		int tmp;
		for(int i=0;i<n;++i){
			cin >> tmp;
			q.push(tmp);
		}

		int res = 0;
		while(q.size()!=1){
			int a, b;
			a = q.top();
			q.pop();
			b = q.top();
			q.pop();
			int c = a + b;
			res += c;
			q.push(c);
		}

		cout << res << '\n';
	}
}