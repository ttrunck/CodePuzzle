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

bool is_prime(int n){
	for(int i=2;i*i<=n;++i)
		if(n%i==0)
			return false;
	return true;
}

ll powMod(ll x, ll n, ll m) {
	ll y = 1;
	while (n != 0) {
		if ((n & 1) == 1)
			y = (y * x) % m;
		x = (x * x) % m;
		n = n >> 1;
	}
	return y;
}

ll inv_mod(ll x, ll p) { return powMod(x, p - 2, p); }


int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	if(n==1){
		cout << "YES\n";
		cout << "1\n";
	}
	else if(n==4){
		cout << "YES\n";
		cout << "1\n3\n2\n4\n";
	}
	else{
		if(is_prime(n)){
			cout << "YES\n";
			cout << "1\n";
			for(ll i=2;i<=n;++i){
				ll val = (i*inv_mod(i-1, n))%n;
				if(val==0)
					val+=n;
				cout << val << '\n';
			}
		}
		else
			cout << "NO\n";
	}
}