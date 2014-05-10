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
	
	int T;
	cin >> T;
	while(T--){
		int n, b, c;
		cin >> n >> b >> c;
		vector<int> go(101);
		for(int i=0;i<101;++i)
			go[i]=i;
		for(int i=0;i<b;++i){
			int x,y;
			cin >> x >> y;
			go[x] = y;
		}
		vector<int> pos(n, 1);
		bool fini = false;
		for(int i=0;i<c;++i){
			int dep;
			cin >> dep;
			if(!fini){
				pos[i%n] += dep;
				pos[i%n] = go[pos[i%n]];
				if(pos[i%n] >= 100){
					pos[i%n] = 100;
					fini = true;
				}
			}
		}
		for(int i=0;i<n;++i)
			cout << "Position of player " << i+1 << " is " << pos[i] << ".\n";
	}
}