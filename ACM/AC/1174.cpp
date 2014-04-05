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

struct triple{
	string a,b;
	int c;
	triple(string aa="", string bb="", int cc=0){
		a = aa;
		b = bb;
		c = cc; 
	}
	bool operator<(const triple& t) const{
		return c<t.c;
	}
};

int find(int x, vector<int>& p){
	int xx = x;
	while(p[xx]!=xx)
		xx = p[xx];
	return p[x] = xx;
}

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
		int n, m;
		cin >> n >> m;
		vector<int> p(n);
		for(int i=0;i<n;++i)
			p[i]=i;
		vector<triple> t(m);
		set<string> ville;
		map<string, int> conv;

		for(int i=0;i<m;++i){
			cin >> t[i].a >> t[i].b >> t[i].c;
			ville.insert(t[i].a);
			ville.insert(t[i].b);
		}

		auto it = begin(ville);
		for(int i=0;i<n;++i, ++it)
			conv[*it] = i;
		sort(begin(t), end(t));
		int res = 0;

		for(const triple& x:t){
			if(find(conv[x.a], p) != find(conv[x.b], p)){
				res += x.c;
				p[find(conv[x.a], p)] = conv[x.b];
			}
		}
		cout << res << '\n';
	}
}