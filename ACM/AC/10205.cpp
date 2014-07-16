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

typedef pair<int, int> pi;
typedef long long ll;



void print(const pi& p){
	if(p.first==14)
		cout << "Ace";
	else if(p.first==11)
		cout << "Jack";
	else if(p.first==12)
		cout << "Queen";
	else if(p.first==13)
		cout << "King";
	else
		cout << p.first;

	cout << " of ";

	if(p.second == 0)
		cout << "Clubs\n";
	else if(p.second == 1)
		cout << "Diamonds\n";
	else if(p.second == 2)
		cout << "Hearts\n";
	else
		cout << "Spades\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	for(int icase=0;icase<T;++icase){
		if(icase!=0) cout << '\n';
		vector<pi> res;
		for(int i=0;i<4;++i)
			for(int j=2;j<15;++j)
				res.push_back(pi{j, i});
		vector<int> ab(52);
		for(int i=0;i<52;++i)
			ab[i]=i;
		int n;
		cin >> n;
		vector<vector<int>> t(n, vector<int>(52));
		for(int i=0;i<n;++i)
			for(int j=0;j<52;++j){
				cin >> t[i][j];
				--t[i][j];
			}
		cin.ignore();
		string s;
		while(getline(cin, s) && s!= ""){
			istringstream ss(s);
			int trans;
			ss >> trans;
			--trans;
			vector<int> tmp(52);
			for(int i=0;i<52;++i)
				tmp[i] = ab[t[trans][i]];
			for(int i=0;i<52;++i)
				ab[i] = tmp[i];
		}

		for(auto& x:ab)
			print(res[x]);
	}
}