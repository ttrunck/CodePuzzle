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
typedef pair<int, char> pi;

const int MOD = 1000000009;

ll aux(int pos, vector<ll>& mem, const vector<pi>& t){
	if(pos>=int(t.size())-1)
		return 1;
	if(mem[pos]!=-1)
		return mem[pos];
	if(t[pos].second == t[pos+1].second)
		return mem[pos] = aux(pos+1, mem, t);
	return mem[pos] = ((t[pos+1].first-t[pos].first)*aux(pos+1, mem, t))%MOD;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--){
		int n, m;
		cin >> n >> m;
		vector<pi> t(m);
		for(int i=0;i<m;++i)
			cin >> t[i].second >> t[i].first;
		sort(begin(t), end(t));
		vector<ll> mem(m, -1);
		cout << aux(0, mem, t) << '\n';
	}
}