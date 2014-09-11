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

const ll LIM = 10000000009ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<ll> t{0, 1};
	ll next_fibo;
	do{
		next_fibo = t.back() + t[t.size()-2];
		t.push_back(next_fibo);
	}while(next_fibo < LIM);

	int tcase;
	cin >> tcase;
	while(tcase--){
		ll n;
		cin >> n;
		if(binary_search(begin(t), end(t), n))
			cout << "IsFibo\n";
		else
			cout << "IsNotFibo\n";
	}
}