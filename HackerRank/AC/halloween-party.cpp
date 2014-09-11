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
		int k;
		cin >> k;
		ll a=k/2;
		ll b=k-a;
		cout << a*b << '\n';
	}
}