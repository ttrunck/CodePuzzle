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

	vector<bool> p(4000, true);
	p[0] = p[1] = false;
	for(int i=2;i<4000;++i)
		if(p[i])
			for(int j=i+i;j<4000;j+=i)
				p[j]=false;

	while(T--){
		int x, y;
		cin >> x >> y;
		int curr = x+y+1;
		while(!p[curr])++curr;
		cout << curr-x-y << '\n';
	}
}