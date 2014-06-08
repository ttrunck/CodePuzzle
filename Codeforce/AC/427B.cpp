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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, s, c;
	cin >> n >> s >> c;
	vector<int> t(n);
	for(int i=0;i<n;++i)
		cin >> t[i];
	int d=0, f=0;
	int res = 0;
	while(d<n && f<n){
		if(t[f]>s)
			d=f+1;
		else if(f-d+1==c){
			++res;
			++d;
		}
		++f;
	}
	cout << res << '\n';
}