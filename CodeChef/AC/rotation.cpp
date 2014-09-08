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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<int> t(n);
	for(int i=0;i<n;++i)
		cin >> t[i];
	int curr = 0;
	for(int i=0;i<m;++i){
		char q; int x;
		cin >> q >> x;
		if(q == 'C')
			curr = (curr+x)%n;
		else if(q == 'A')
			curr = (curr+n-x)%n;
		else
			cout << t[(curr-1+x)%n] << '\n';
	}
}