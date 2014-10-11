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

const int INF = 1000000000;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--){
		string s, w;
		cin >> s >> w;
		int n = s.size();
		int m = w.size();
		int a, b, k;
		cin >> a >> b >> k;
		if(a == 0){
			cout << "0\n";
			continue;
		}
		if(b == 0){
			int cost = abs(m-n)*a;
			cout << ((cost<=k)?cost:-1) << '\n';
			continue;
		}

		vector<int> t(2*k+3, INF);
		for(int i=0;i<=min(n, k);++i)
			t[k+1+i] = a*i;

		for(int i=0;i<m;++i){
			vector<int> tmp(2*k+3, INF);

			for(int j=max(1, k-i);j<=2*k+1 && i+j-k-1<n;++j){
				
				tmp[j] = min(tmp[j], tmp[j-1] + a);
				tmp[j] = min(tmp[j], t[j+1] + a);
				if(i+j-k-1 >=0 && s[i+j-k-1]==w[i])
					tmp[j] = min(tmp[j], t[j]);
				else
					tmp[j] = min(tmp[j], t[j] + b);
			}
			t.swap(tmp);
		}

		cout << ((k+1+n-m>=0 && k+1+n-m<2*k+3 && t[k+1+n-m]<=k)?t[k+1+n-m]:-1) << '\n';
	}
}