#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

typedef long long ll;

void solve(int x, int p, bool pred, bool predpred, const vector<vector<int>>& t, const vector<bool>& start, const vector<bool>& cible, vector<int>& res){
	bool change = predpred ^ start[x] ^ cible[x];
	if(change)
		res.push_back(x);
	for(int v:t[x]){
		if(v==p) continue;
		solve(v,x,change^predpred,pred,t,start,cible,res);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<vector<int>> t(n);
	for(int i=0;i<n-1;++i){
		int a, b;
		cin >> a >> b;
		t[a-1].push_back(b-1);
		t[b-1].push_back(a-1);
	}
	vector<bool> start(n);
	for(int i=0;i<n;++i){
		int tmp;
		cin >> tmp;
		start[i] = tmp==1;
	}
	vector<bool> cible(n);
	for(int i=0;i<n;++i){
		int tmp;
		cin >> tmp;
		cible[i] = tmp==1;
	}
	vector<int> res;

	solve(0, 0, false, false, t, start, cible, res);

	cout << res.size() << '\n';
	for(int x:res)
		cout << x+1 << '\n';
}