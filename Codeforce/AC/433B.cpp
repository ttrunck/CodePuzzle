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
	vector<int> v(n), u(n);
	for(int i=0;i<n;++i){
		cin >> v[i];
		u[i] = v[i];
	}
	sort(begin(u), end(u));
	vector<ll> vv(n+1), uu(n+1);

	for(int i=0;i<n;++i){
		vv[i+1] = vv[i] + v[i];
		uu[i+1] = uu[i] + u[i];
	}

	int q;
	cin >> q;
	for(int i=0;i<q;++i){
		int t,l,r;
		cin >> t >> l >> r;
		if(t==1)
			cout << vv[r] - vv[l-1] << '\n';
		else
			cout << uu[r] - uu[l-1] << '\n';
	}

}