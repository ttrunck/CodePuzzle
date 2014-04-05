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

bool pref(int g1, int g2, const vector<int>& t){
	for(int x:t)
		if(x==g1)
			return true;
		else if(x==g2)
			return false;

	assert(false);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int nbcase;
	bool first=true;
	cin >> nbcase;
	while(nbcase--){
		if(!first)
			cout << '\n';
		first = false;
		int n;
		cin >> n;
		vector<vector<int>> prefg(n, vector<int>(n));
		vector<vector<int>> prefb(n, vector<int>(n));
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				cin >> prefg[i][j];
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				cin >> prefb[i][j];
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j){
				prefg[i][j]--;
				prefb[i][j]--;
			}

		vector<int> coupg(n, -1);
		vector<int> coupb(n, -1);

		int g=0;
		while(true){
			while(g<n && coupg[g]!=-1)++g;
			if(g==n) break;

			for(int b:prefg[g]){
				if(coupb[b]==-1){
					coupb[b]=g;
					coupg[g]=b;
					break;
				}
				else if(pref(g, coupb[b], prefb[b])){
					coupg[g]=b;
					coupg[coupb[b]]=-1;
					coupb[b]=g;
					break;
				}
			}
		g=0;
		}
		for(int b:coupg)
			cout << b+1 << '\n';
	}	
}