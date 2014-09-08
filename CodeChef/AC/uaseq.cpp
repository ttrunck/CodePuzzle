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
typedef pair<int, int> pi;

const int INF = 1000000000;

void print(const pi& p, int n){
	for(int i=0;i<n;++i)
		cout << p.first+i*p.second << (i==n-1?'\n':' ');
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<int> t(n);
	for(int i=0;i<n;++i)
		cin >> t[i];

	pi p{INF, INF};
	for(int i=0;i<min(n, 12);++i){
		map<int, int> count;
		for(int j=0;j<n;++j){
			if(j==i) continue;
			count[(t[i]-t[j])/(i-j)]++;
		}
		for(auto& pp:count)
			if(pp.second+1>=n-k){
				int d = pp.first;
				int a = t[i]-i*d;
				p = min(p, pi{a, d});
			}
	}

	print(p, n);

}