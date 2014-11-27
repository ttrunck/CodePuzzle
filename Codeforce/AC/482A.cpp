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
	int n, k;
	cin >> n >> k;
	int m = 1;

	int curr = 1;
	cout << curr;
	for(int i=1;i<n-k;++i){
		++curr;
		cout << ' ' << curr;

	}
	for(int i=k;i>0;--i){
		curr += m*i;
		m = -m;
		cout << ' ' << curr;
	}
	cout << '\n';

}