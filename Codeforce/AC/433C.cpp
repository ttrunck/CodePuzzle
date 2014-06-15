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

using namespace std;

typedef long long ll;

const int INF = numeric_limits<int>::max();

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<int> t(m);
	for(int i=0;i<m;++i){
		cin >> t[i];
		--t[i];
	}
	vector<vector<int>> b(n);
	for(int i=0;i<m;++i){
		if(i>0 && t[i-1]!=t[i])
			b[t[i]].push_back(t[i-1]);
        if(i<m-1 && t[i+1]!=t[i])
        	b[t[i]].push_back(t[i+1]);
    }
    ll sum = 0;
    for(int k=0;k<m-1;++k)
    	sum += abs(t[k]-t[k+1]);

    ll res = sum;

    for(int i=0;i<n;++i)
    	if(!b[i].empty()){
    		sort(begin(b[i]), end(b[i]));
    		int j = b[i][b[i].size()/2];
    		ll old = 0, now = 0;
    		for(int x:b[i]){
    			old += abs(x-i);
    			now += abs(x-j);
    		}
    		res = min(res, sum-old+now);
    	}
    cout << res << '\n';
}