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

int destroy(int a, int b, int x, const vector<int>& t){
	int n = t.size();
	if(a<0 || b>=n) return 0;
	int res = 0;
	if(t[a]==t[b] && t[a]==x){
		++res;
		while(a>=0 && t[a]==x){--a;++res;}
		while(b<n && t[b]==x){++b;++res;}
		res += max(destroy(a-1, b, t[a], t), destroy(a, b+1, t[b], t));
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k, x;
	cin >> n >> k >> x;
	vector<int> t(n);
	for(int i=0;i<n;++i)
		cin >> t[i];
	int res = 0;
	for(int i=0;i<n-1;++i)
		res = max(res, destroy(i, i+1, x, t)-1);
	cout << res << '\n';
}