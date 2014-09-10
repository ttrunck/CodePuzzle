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
	
	int n, t;
	cin >> n >> t;
	vector<int> width(n);
	for(int i=0;i<n;++i)
		cin >> width[i];

	while(t--){
		int i, j;
		cin >> i >> j;
		int res = width[i];
		for(int ii=i;ii<=j;++ii)
			res = min(res, width[ii]);
		cout << res << '\n';
	}

}