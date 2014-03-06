#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

map<pair<pi, bool>, ll> mem;

ll binomial(ll k, ll n) {
	ll res = 1;
	for (ll i = 1; i <= k; ++i)
		res = (n - k + i) * res / i;
	return res;
}

ll aux(int l, int c, bool inv){
	if(l==0)
		return (inv?1:0);

	pair<pi, bool> elt{pi{c, l}, inv};
	auto it = mem.find(elt);
	if(it!=end(mem)) return it->second;

	ll res = 0;
	if(!inv)
		for(int i=c; i<l;++i)
			res+=aux(l-1, i, true);
	for(int i=0;i<c;++i)
		res+=aux(l-1, i, inv);

	return mem[elt]=res;
}

ll aux2(int n){
	ll res = 0;
	for(int i=0;i<n;++i)
		res += aux(n-1, i, false);	
	return res*binomial(n, 26);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	 ll res = 0;
	 for(int i=0;i<26;++i)
	 	res = max(res, aux2(i));
	 cout << res << '\n';
}