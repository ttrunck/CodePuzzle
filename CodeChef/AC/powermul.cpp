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

int rem(int n, const vector<int>& t){
	for(int p:t)
		while(n%p==0) n/=p;
	return n;
}

ll calcul(const vector<ll>& expo, const vector<int>& prime, int m){
	ll res = 1;
	for(int i=0;res && i<int(expo.size());++i)
		res = (res * powMod(prime[i], expo[i], m))%m;
	return res;
}

void factor(int n, int a, vector<ll>& expo, const vector<int>& p){
	for(int i=0;n>1; ++i){
		while(n%p[i]==0){
			n/=p[i];
			expo[i] += a;
		}
	}
}

ll gcd(ll a, ll b){
	return b?gcd(b,a%b):a;
}

ll extended_euclid(ll a, ll b, ll &x, ll &y) {  
	ll xx = y = 0;
	ll yy = x = 1;
	while (b) {
		ll q = a/b;
		ll t = b; b = a%b; a = t;
		t = xx; xx = x-q*xx; x = t;
		t = yy; yy = y-q*yy; y = t;
	}
	return a;
}

ll mod_inverse(ll a, ll n) {
	ll x, y;
	ll d = extended_euclid(a, n, x, y);
	if(d!=1){
		cerr << a << ' ' << n << endl;
		assert(d == 1);
	}
	return ((x%n)+n)%n;
}

ll build(ll n, int p){
	ll res = 0;
	ll curr = p;
	while(curr<=n){
		ll tmp = n/curr;
		res += curr*(tmp*(tmp+1))/2;
		curr *= p;
	}
	return res;
}


int main(){

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<bool> p(100000,true);
	p[0] = p[1] = false;
	for(int i=2;i<int(p.size());++i)
		for(int j=i+i;j<int(p.size());j+=i)
			p[j] = false;

		vector<int> prime;
		for(int i=0;i<int(p.size());++i)
			if(p[i])
				prime.push_back(i);

			int t;
			cin >> t;
			while(t--){
				int n,m,q;
				cin >> n >> m >> q;

				if(n<10){
					vector<int> tr(q); 
					vector<ll> value(n+1,0);

					for(int k=0;k<q;++k){
						cin >> tr[k];
						value[tr[k]] = -1;
					}
					value[0] = 1;

					vector<ll> expo(distance(begin(prime), lower_bound(begin(prime), end(prime), n)+1), 0);
					for(int i=1;i<=n;++i){
						factor(n+1-i, n+1-i, expo, prime);
						factor(i, -i, expo, prime);
						if(value[i]==-1)
							value[i] = calcul(expo, prime, m);
					}

					
					for(int r:tr)
						cout << value[r] << '\n';
				}
				else{
					int mm = m;
					vector<int> pdec;
					for(int i=0;mm>1 && i<int(prime.size());++i)
						if(mm%prime[i]==0){
							pdec.push_back(prime[i]);
							while(mm%prime[i]==0) mm/=prime[i];
						}
						if(mm!=1)
							pdec.push_back(mm);

						vector<ll> f(n+1);
						f[0] = 1;
						f[1] = 1;
						for(int i = 2;i<=n;++i)
							f[i] = (f[i-1] * powMod(rem(i, pdec),i,m))%m;

						for(int k=0;k<q;++k){
							int r;
							cin >> r;
							ll tmp = (f[n] * mod_inverse(f[r], m)) % m;
							tmp = (tmp * mod_inverse(f[n-r], m)) % m;

							for(int p : pdec){
								ll expo = build(n, p);
								expo -= build(r, p);
								expo -= build(n-r, p);
								tmp = (tmp * powMod(p, expo, m)) % m;
							}

							cout << tmp << '\n';
						}
					}

				}
			}