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
	vector<int> t(4);
	for(int i=0;i<4;++i){
		string s;
		cin >> s;
		t[i] = s.size()-2;
	}

	vector<int> g;
	for(int i=0;i<4;++i){
		bool mini = true;
		bool maxi = true;
		for(int j=0;j<4;++j){
			if(i==j) continue;
			if(t[i]*2>t[j]) mini = false;
			if(t[i]<2*t[j]) maxi = false;
		}
		if(mini || maxi)
			g.push_back(i);
	}


	if(g.size()==1)
		cout << char('A' + g[0]) << '\n';
	else
		cout << "C\n";

}