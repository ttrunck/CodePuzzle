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
	int n;
	cin >> n;
	vector<ll> t(n);
	for(int i=0;i<n;++i)
		cin >> t[i];
	ll cible=0;
	for(int x:t)
		cible += x;
	cible/=n;
	ll res = 0;
	for(int i=0;i<n;++i){
		if(t[i]<cible){
			res+=cible-t[i];
			t[i+1]-=cible-t[i];
			t[i]+=cible-t[i];
		}
		else if(t[i]>cible){
			res+=t[i]-cible;
			t[i+1]+=t[i]-cible;
			t[i]-=t[i]-cible;
		}
	}


	cout << res << '\n';
}