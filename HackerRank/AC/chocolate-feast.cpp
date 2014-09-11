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
	int t;
	cin >> t;
	while(t--){
		int n, c, m;
		cin >> n >> c >> m;
		int res = 0, w=0;
		while(n>=c || w>=m){
			res += n/c;
			w += n/c;
			n %= c;

			int tmp = w/m;
			res += tmp;
			w %= m;
			w += tmp;
		}

		cout << res << '\n';

	}
}