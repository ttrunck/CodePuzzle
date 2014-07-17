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
	for(int icase = 1;icase<=T;++icase){
		cout << "Case " << icase << ": ";
		vector<string> t(52);
		for(int i=0;i<52;++i)
			cin >> t[i];
		int y = 0;
		int curr = 51-25;
		for(int i=0;i<3;++i){
			int val = (isdigit(t[curr][0])?t[curr][0]-'0':10);
			y += val;
			for(int j=curr;j>curr-10+val-1;--j)
				t.erase(t.begin() + j);
			curr -= 10-val+1;
		}
		cout << t[y-1] << '\n';
	}
}