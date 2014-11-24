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

const int INF = 1000000001;

int spread(const multiset<int>& st){
	int mini = *begin(st);
	int maxi = *(--end(st));
	return maxi-mini;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, s, l;
	cin >> n >> s >> l;
	vector<int> t(n);
	for(int i=0;i<n;++i)
		cin >> t[i];

	vector<int> res(n+1, INF);
	res[0] = 0;

	int start = 0;
	multiset<int> curr;
	curr.insert(t[0]);
	for(int fin=0;fin<n;){
		if(spread(curr)>s || res[start]==INF){
			++start;
			auto it = curr.find(t[start-1]);
			curr.erase(it);
			if(curr.empty())
				break;
		}
		else{
			if(int(curr.size())>=l)
				res[fin+1] = min(res[fin+1], res[start]+1);
			++fin;
			if(fin<n)
				curr.insert(t[fin]);
		}
	}

	cout << ((res[n]==INF)?-1:res[n]) << '\n';
}