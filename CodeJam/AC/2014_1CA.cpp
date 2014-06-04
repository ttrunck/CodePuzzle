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

ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b, a%b);
}

bool impossible(ll q){
	int nb=0;
	while(q!=0){
		if(q%2 == 1)
			++nb;
		q/=2;
	}
	return nb!=1;
}

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int icase = 1;icase<=T;++icase){
		cout << "Case #" << icase << ": ";
		ll p, q;
		char tmp;
		cin >> p >> tmp >> q;
		ll g = gcd(p, q);
		p/=g;
		q/=g;

		if(impossible(q))
			cout << "impossible\n";
		else{
			ll curr = 1;
			ll val = 2;
			while(curr<=40 && val*p<q){
				++curr;
				val*=2;
			}
			if(curr > 40)
				cout << "impossible\n";
			else
				cout << curr << '\n';
		}
	}
}