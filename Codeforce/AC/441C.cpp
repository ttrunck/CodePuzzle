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
typedef pair<int, int> pi;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m , k;
	cin >> n >> m >> k;
	vector<pi> t{pi{1,1}};
	int d = 1;
	for(int i=1;i<n*m;++i){
		int x = t.back().first;
		int y = t.back().second;
		y += d;
		if(y>m || y<=0){
			++x;
			y -= d;
			d *=-1;
		}
		t.push_back(pi{x, y});
	}
	int curr = 0;
	for(int i=0;i<k-1;++i){
		cout << 2;
		cout << ' ' << t[curr].first << ' ' << t[curr].second;
		++curr;
		cout << ' ' << t[curr].first << ' ' << t[curr].second;
		++curr;
		cout << '\n';
	}
	cout << t.size()-curr;
	while(curr<t.size()){
		cout << ' ' << t[curr].first << ' ' << t[curr].second;
		++curr;
	}
	cout << '\n';

}