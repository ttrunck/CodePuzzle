#include <algorithm>
#include <cassert>
#include <iostream>
#include <iomanip>
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
		double x;
		ll k;
		cin >> x >> k;
		double start = x/2;
		ll nbpt = 1;
		while(k>nbpt){
			k -= nbpt;
			nbpt *= 2;
			start/=2;
		}
		cout << fixed << setprecision(8) << start + (k-1)*start*2 << '\n';
	}
}