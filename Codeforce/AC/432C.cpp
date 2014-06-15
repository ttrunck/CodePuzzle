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
const int N = 200000;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<bool> p(N, true);
	vector<int> prime;
	p[0] = p[1] = false;
	for(int i=2;i<N;++i)
		if(p[i]){
			prime.push_back(i);
			for(int j=i+i;j<N;j+=i)
				p[j]=false;
		}

	vector<int> t(n), pos(n);
	for(int i=0;i< n;++i){
		cin >> t[i];
		--t[i];
		pos[t[i]] = i; 
	}
	vector<pi> res;
	for(int i=0;i<n;++i)
		while(pos[i]!=i){
			int p = 0;
			while(pos[i]-i+1>=prime[p])
				++p;
			--p;
			//swap pos, pos-p+1
			int p1 = pos[i], p2=pos[i]-prime[p]+1;
			res.push_back(pi{p1, p2});
			pos[t[p2]] = p1;
			pos[i] = p2;
			swap(t[p1], t[p2]);
		}


	cout << res.size() << '\n';
	for(auto& p:res)
		cout << p.second+1 << ' ' << p.first+1 << '\n';
}