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

struct triple{
	int x, y, d;
	triple(int xx, int yy, int dd):x(xx), y(yy), d(dd){};
	bool operator< (const triple& t) const{
		return d<t.d;
	}
};

int find(int x, vector<int>& p){
	if(p[x]==-1) return x;
	return p[x] = find(p[x], p);
}

void print(int x, int p, const vector<vector<int>>& t){
	for(int elt:t[x])
		if(elt!=p){
			cout << elt << ' ' << x << '\n';
			print(elt, x, t);
		}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k, w;
	cin >> n >> m >> k >> w;
	vector<vector<string>> level(k, vector<string>(n));
	for(int i=0;i<k;++i)
		for(int j=0;j<n;++j)
			cin >> level[i][j];

	vector<triple> edge;
	for(int i=0;i<k;++i)
		edge.push_back(triple(0, i+1, n*m));
	for(int l1=0;l1<k;++l1)
		for(int l2=l1+1;l2<k;++l2){
			int diff = 0;
			for(int i=0;i<n;++i)
				for(int j=0;j<m;++j)
					if(level[l1][i][j]!=level[l2][i][j])
						++diff;
			edge.push_back(triple(l1+1, l2+1, diff*w));
		}

	sort(begin(edge), end(edge));
	vector<int> p(k+1, -1);
	int res = 0;
	vector<vector<int>> tree(k+1);
	for(auto& t:edge){
		if(find(t.x, p)!=find(t.y, p)){
			res += t.d;
			p[find(t.x, p)] = t.y;
			tree[t.x].push_back(t.y);
			tree[t.y].push_back(t.x);
		}
	}

	cout << res << '\n';
	print(0, 0, tree);
}