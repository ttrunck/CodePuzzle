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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<string, pair<string, int>> mem;

	string s;
	while(cin >> s && s!="#"){
		string ss(s);
		for(auto& x:ss)
			x = tolower(x);

		sort(begin(ss), end(ss));
		if(mem.find(ss)!=end(mem)){
			if(mem[ss].first>s)
				mem[ss].first = s;
			mem[ss].second++;
		}
		else
			mem[ss] = make_pair(s, 1);
	}

	vector<string> res;
 	for(const auto& x:mem)
 		if(x.second.second==1)
	 		res.push_back(x.second.first);
	 sort(begin(res), end(res));
	 for(const auto& x:res)
	 	cout << x << '\n';
}