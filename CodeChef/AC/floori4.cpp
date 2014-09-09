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

ll s4(const ll n, const ll M){
	ll MM = 30*M;
	ll nn = n%(MM);
	ll sn = (nn*(nn+1))%MM;
	sn = (sn*(2*nn+1))%MM;
	ll aux = (3*nn*nn+3*nn-1)%MM;
	sn = (sn*aux)%MM;
	sn/=30;
	return sn%M;
}


ll s4(ll a, ll b, ll M){
	ll sb = s4(b, M);
	ll sa = s4(a-1, M);
	return ((sb-sa)%M+M)%M;
}

ll compute(ll n, ll m){
	ll d;
	ll res = 0; 
	for(d=1;d*d<=n;++d){
		res = (res + d*s4(n/(d+1)+1, n/d, m))%m;
	}
	--d;

	for(ll k=1;k<=n/(d+1);++k){
		ll k4 = (k*k)%m;
		k4 = (k4*k4)%m;
		res = (res+k4*(n/k))%m;
	}

	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	ll n;
	ll m;

	while(t--){
		cin >> n >> m;
		ll res = compute(n, m);
		cout << res << '\n';
	}
}