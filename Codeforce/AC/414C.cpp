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

void mergesort(int deb, int n, vector<int>&t, vector<ll>& inv, vector<ll>& eg){
	if(n==0) return;
	mergesort(deb, n-1, t, inv, eg);
	mergesort(deb+(1<<(n-1)), n-1, t, inv, eg);

	vector<int> res(1<<n);
	int curr1=deb, curr2=deb+(1<<(n-1));

	for(int i=0;i<(1<<n);++i)
		if(curr1<deb+(1<<(n-1)) && (curr2>=deb+(1<<n) || t[curr1]<t[curr2])){
			res[i] = t[curr1];
			++curr1;
		}
		else if(curr1<deb+(1<<(n-1)) && curr2<deb+(1<<n) && t[curr1]==t[curr2]){
			res[i] = t[curr1];
			++curr1;
			eg[n-1] += 1;
		}
		else{
			res[i] = t[curr2];
			++curr2;
			inv[n-1] += deb+(1<<(n-1)) - curr1;
		}

	for(int i=0;i<1<<n;++i)
		t[deb+i] = res[i];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> t(1<<n);
	for(int i=0;i<1<<n;++i)
		cin >> t[i];
	vector<ll> inv(n, 0);
	vector<ll> eg(n, 0);
	vector<ll> tot(n);
	for(int i=0;i<n;++i){
		tot[i] = ll{1<<i} * ll{1<<i};
		tot[i] *= ll{1<<(n-1-i)};
	}

	//inv[i] = nombre d'inversion par bloc de taille 2^(i+1)

	mergesort(0, n, t, inv, eg);

	int q;
	cin >> q;
	for(int query=0;query<q;++query){
		int qi;
		cin >> qi;	
		for(int i=0;i<qi;++i)
			inv[i] = tot[i] - inv[i] - eg[i];
		ll res = 0;
		for(ll x:inv)
			res += x;
		cout << res << '\n';
	}

}