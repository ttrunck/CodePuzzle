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
	int T;
	cin >> T;
	while(T--){
		int M;
		vector<int> nb(3);
		cin >> nb[0] >> nb[1] >> nb[2] >> M;
		vector<int> t(3,0);
		for(int i=0;i<3;++i)
			for(int j=0;j<nb[i];++j){
				int tmp;
				cin >> tmp;
				t[i] = max(t[i], tmp);
			}
		int res = max(t[0], max(t[1], t[2]));
		for(int m=0;m<M;++m){
			int pos = 0, maxi = t[0];
			for(int i=1;i<3;++i)
				if(t[i]>maxi){
					pos = i;
					maxi = t[i];
				}
			// for(int i=0;i<3;++i)
			// 	if(i!=pos)
			// 		t[i]++;
			t[pos]/=2;
			maxi = max(t[0], max(t[1], t[2]));
			res = min(res, maxi);
		}
		cout << res << '\n';
	}
}