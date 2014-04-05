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
typedef pair<string, int> ps;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int nbcase;
	cin >> nbcase;
	while(nbcase--){
		int n1;
		cin >> n1;
		vector<ps> t1(n1);
		for(int i=0;i<n1;++i){
			string tmp, s;
			int x;
			cin >> tmp >> s >> x;
			t1[i] = ps(s, x);
		}

		int n2;
		cin >> n2;
		vector<ps> t2(n2);
		for(int i=0;i<n2;++i){
			string tmp, s;
			int x;
			cin >> tmp >> s >> x;
			t2[i] = ps(s, x);
		}

	if(n1==0 || n2==0){
		cout << 0 << ' ' << 0 << '\n';
		continue;
	}

		vector<vector<pi>> mem(n1, vector<pi>(n2, pi(0,0)));
		for(int i=0;i<n1;++i){
			if(i>0)
				mem[i][0] = mem[i-1][0];
			if(t1[i].first == t2[0].first && t1[i].second+t2[0].second > mem[i][0].first){
				mem[i][0].first = t1[i].second+t2[0].second;
				mem[i][0].second = 1;
			}
		}

		for(int j=0;j<n2;++j){
			if(j>0)
				mem[0][j] = mem[0][j-1];
			if(t1[0].first == t2[j].first && t1[0].second+t2[j].second > mem[0][j].first){
				mem[0][j].first = t1[0].second+t2[j].second;
				mem[0][j].second = 1;
			}
		}

		for(int i=1;i<n1;++i)
			for(int j=1;j<n2;++j){
				mem[i][j] = mem[i-1][j];
				pi tmp = mem[i][j-1];
				if(tmp.first>mem[i][j].first || (tmp.first==mem[i][j].first && tmp.second<mem[i][j].second))
					mem[i][j] = tmp;
				if(t1[i].first == t2[j].first){
					tmp = mem[i-1][j-1];
					tmp.first += t1[i].second + t2[j].second;
					tmp.second++;
					if(tmp.first>mem[i][j].first || (tmp.first==mem[i][j].first && tmp.second<mem[i][j].second))
						mem[i][j] = tmp;
				}
			}

		// for(auto& t:mem){
		// 	for(pi& p:t)
		// 		cerr << '(' << p.first << ',' << p.second << ')' << '\t';
		// 	cerr << endl;
		// }
	
		cout << mem[n1-1][n2-1].first << ' ' << mem[n1-1][n2-1].second << '\n';
	}
}