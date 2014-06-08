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
	vector<vector<int>> g(5, vector<int>(5));
	for(int i=0;i<5;++i)
		for(int j=0;j<5;++j)
			cin >> g[i][j];
	vector<int> t{0,1,2,3,4};
	int res = 0;
	do{
		int tmp=0;
		for(int i=0;i<5;++i)
			for(int j=i;j<5-1;j+=2)
				tmp += g[t[j]][t[j+1]] + g[t[j+1]][t[j]];
		res = max(res, tmp);
	}while(next_permutation(begin(t), end(t)));
	cout << res << '\n';
}