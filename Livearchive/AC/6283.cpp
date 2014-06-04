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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n, k;
	while(cin >> n >> k){
		vector<int> dec;
		while(n){
			dec.push_back(n%k);
			n/=k;
		}
		ll res = 0;
		bool ok = false;
		for(int i=int(dec.size())-1;i>=0;--i){
			if(i%2==0)
				res = res*k + (ok?k-1:dec[i]);
			else if(!ok && dec[i]!=0)
				ok = true;
		}
		cout << res + 1  << '\n';
	}
}