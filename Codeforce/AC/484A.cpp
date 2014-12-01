#include <algorithm>
#include <bitset>
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

typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i){
		ull l, r;
		cin >> l >> r;
		bitset<64> b{l};
		ull res = l;
		int curr = 0;
		while ( curr < 64 ){
			if(b[curr] == 0) {
				b[curr] = 1;
				ull tmp = b.to_ullong();
				if(tmp<=r)
					res = tmp;
			}
			++curr;
		}

		cout << res << '\n';
	}

}