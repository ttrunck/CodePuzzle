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
#include <cmath>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--){
		int a, b;
		cin >> a >> b;
		int res = 0;
		int curr = sqrt(a);
		if(curr*curr!=a) ++curr;
		for(;curr*curr<=b;++curr)
			++res;
		cout << res << '\n';
	}
}