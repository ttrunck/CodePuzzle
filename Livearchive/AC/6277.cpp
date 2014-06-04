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
	
	int h, w, c;
	while(cin >> h >> w >> c){
		vector<int> t(c);
		vector<vector<int>> res(h, vector<int>(w));
		for(int i=0;i<c;++i)
			cin >> t[i];

		int x=0, y=0, dir=1;
		for(int i=0;i<c;++i)
			for(int j=0;j<t[i];++j){
				res[x][y] = i+1;
				y+=dir;
				if(y==-1){
					dir = -dir;
					y = 0;
					++x;
				}
				else if(y==w){
					dir = -dir;
					y = w-1;
					++x;
				}
			}

		for(int i=0;i<h;++i){
			for(int j=0;j<w;++j)
				cout << res[i][j];
			cout << '\n';
		}

	}
}