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

const int W = 13;

bool is_last(int N, int M){
	vector<bool> t(N, true);

	int curr = 0;
	for(int i=0;i<N-1;++i){
		//cerr << curr << ' ';
		if(curr == W-1)
			return false;
		t[curr] = false;
		int m = M;
		while(m){
			curr = (curr + 1)%N;
			if(t[curr])
				--m;
		}
	}

	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	while(cin >> n && n){
		int res = 1;
		while(!is_last(n, res)) ++res;
		cout << res << endl;
	}
}