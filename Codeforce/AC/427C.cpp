#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <random>
#include <set>
#include <sstream>
#include <cassert>
#include <limits>
#include <stack>

using namespace std;

typedef long long ll;

const int INF = numeric_limits<int>::max();
const int MOD = 1000000007;

struct Tarjan {
	vector<vector<int> > adj;
	vector<int> comp, index, lowlink;
	stack<int> accu;
	int counter, ncomp;

	Tarjan(int n) :
		adj(n), comp(n, -1), index(n, -1), lowlink(n, -1), counter(0), ncomp(0) {}

	void dfs(int i) {
		index[i] = lowlink[i] = counter++;
		accu.push(i);
		for(int k=0;k<adj[i].size();++k) {
			int j = adj[i][k];
			if (index[j] == -1) dfs(j);
			if (comp[j] == -1)
				lowlink[i] = min(lowlink[i], lowlink[j]);
		}
		if (lowlink[i] == index[i]) {
			int j; do {
				j = accu.top(); accu.pop();
				comp[j] = ncomp;
			} while (i != j);
			++ncomp;
		}
	}

	void compute() { for(int i=0;i<adj.size();++i) if (index[i] == -1) dfs(i); }
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> cost(n);
	for(int i=0;i<n;++i)
		cin >> cost[i];
	int m;
	cin >> m;
	Tarjan t(n);
	for(int i=0;i<m;++i){
		int a, b;
		cin >> a >> b;
		t.adj[a-1].push_back(b-1);
	}
	t.compute();
	vector<vector<int>> comp(t.ncomp);
	for(int i=0;i<n;++i)
		comp[t.comp[i]].push_back(i);

	ll nbway = 1;
	ll res=0;
	for(auto& tt:comp){
		int mini = INF;
		int nbmini = 1;
		for(int x:tt){
			if(cost[x]==mini)
				++nbmini;
			else if(cost[x]<mini){
				mini = cost[x];
				nbmini = 1;
			}
		}
		nbway = nbway*nbmini % MOD;
		res += mini;
	}

	cout << res << ' ' << nbway << '\n';
}