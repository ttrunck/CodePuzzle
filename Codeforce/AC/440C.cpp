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

int mini = 100000000;
const int N=16;
vector<ll> t(N);

void dfs(int pos, ll n, int curr){
	if(n==0){
		mini=min(mini, curr);
		return;
	}
	if(pos<0)
		return;

	for(int i=-10;i<=10;++i)
		if(n+i*t[pos]>0){
			dfs(pos-1, n+i*t[pos], curr+abs(i)*(pos+1));
			break;
		}
	for(int i=-10;i<=10;++i)
		if(n+i*t[pos]==0){
			dfs(pos-1, n+i*t[pos], curr+abs(i)*(pos+1));
			break;
		}
	for(int i=10;i>=-10;--i)
		if(n+i*t[pos]<0){
			dfs(pos-1, n+i*t[pos], curr+abs(i)*(pos+1));
			break;
		}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	t[0]=1;
	for(int i=1;i<N;++i)
		t[i] = 10*t[i-1]+1;
	ll n;
	cin >> n;
	dfs(N-1, n, 0);
	cout << mini << '\n';
}