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

const ll MOD = 1000000007;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<ll> a(n), b(m), c(m);
	for(int i=0;i<n;++i)
		cin >> a[i];
	for(int i=0;i<m;++i)
		cin >> b[i];
	for(int i=0;i<m;++i)
		cin >> c[i];

	map<int, ll> prod;
	for(int i=0;i<m;++i){
		if(prod[b[i]]==0)
			prod[b[i]]=1;
		prod[b[i]] = (prod[b[i]]*c[i])%MOD;
	}

	vector<ll> t(n, 1);
	for(auto& p:prod){
		for(int i=p.first;i<=n;i+=p.first)
			t[i-1] = (t[i-1]*p.second)%MOD;
	}


	for(int i=0;i<n;++i)
		cout << (a[i]*t[i])%MOD << ' ';
	cout << '\n';
}