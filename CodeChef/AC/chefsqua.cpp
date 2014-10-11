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
typedef pair<int, int> pi;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<pi> t(n);
	set<pi> s;
	for(int i=0;i<n;++i){
		cin >> t[i].first >> t[i].second;
		s.insert(t[i]);
	}
	if(s.size()==0){
		cout << "4\n";
		return 0;
	}
	if(s.size()==1){
		cout << "3\n";
		return 0;
	}

	int res = 2;
	for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j){
			pi p1, p2;
			int curr = 2;
			int x = t[j].second-t[i].second;
			int y = t[i].first-t[j].first;

			p1 = pi{t[i].first+x, t[i].second+y};
			p2 = pi{t[j].first+x, t[j].second+y};
			if(s.find(p1)!=end(s))
				--curr;
			if(s.find(p2)!=end(s))
				--curr;
			res = min(res, curr);
			
			p1 = pi{t[i].first-x, t[i].second-y};
			p2 = pi{t[j].first-x, t[j].second-y};
			
			curr = 2;
			if(s.find(p1)!=end(s))
				--curr;
			if(s.find(p2)!=end(s))
				--curr;
			res = min(res, curr);
		}
	cout << res << '\n';
}