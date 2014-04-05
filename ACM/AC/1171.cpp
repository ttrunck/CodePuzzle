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
typedef pair<int, int> pi;

const ll INF = numeric_limits<ll>::max();

struct triple{
	int a,b,c;
	triple(int aa=0, int bb=0, int cc=0){
		a=aa;
		b=bb;
		c=cc;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int nbcase;
	cin >> nbcase;
	bool first = true;
	while(nbcase--){
		if(!first)
			cout << '\n';
		first = false;
		int n, deb, fin;
		cin >> n >> deb >> fin;
		int m;
		cin >> m;
		vector<triple> t(m);
		for(int i=0;i<m;++i)
			cin >> t[i].a >> t[i].b >> t[i].c;

		vector<ll> dist(n, INF);
		dist[deb]=0;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				if(dist[t[j].a]!=INF)
					dist[t[j].b] = min(dist[t[j].b], dist[t[j].a] + t[j].c);

		bool ok = true;
		ll res = dist[fin];
		for(int j=0;j<m;++j)
				if(dist[t[j].a]!=INF && dist[t[j].b]>dist[t[j].a] + t[j].c)
					ok = false;
		if(!ok || res == INF)
			cout << "infinity\n";
		else
			cout << res << '\n';
	}

}