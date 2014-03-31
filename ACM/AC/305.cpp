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

bool is_last(int N, int M){
	int curr = 0;
	for(int i=0;i<N;++i){
		curr = (curr - 1 + M)%(N+N-i);
		if(curr < N)
			return false;		
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	vector<int> mem(14);
	for(int n=1;n<14;++n){
		int res = 1;
		while(!is_last(n, res)) ++res;
		mem[n] = res;
	}

	int n;
	while(cin >> n && n)
		cout << mem[n] << '\n';
}