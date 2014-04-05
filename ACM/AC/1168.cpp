#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <random>
#include <set>
#include <sstream>
#include <cassert>
#include <queue>
#include <unordered_set>

using namespace std;

typedef long long ll;

typedef pair<string, int> psi;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first+v.second*1000;
    }
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int nbcase;
	cin >> nbcase;
	bool first = true;
	while(nbcase--){
		if(!first)
			cout << '\n';
		first = false;

		int n1, p1, m1;
		cin >> n1 >> p1 >> m1;
		vector<vector<psi>> t1(n1);
		for(int i=0;i<m1;++i){
			int a, b;
			string s;
			cin >> a >> s >> b;
			t1[a].push_back(psi(s,b));
		}

		int n2, p2, m2;
		cin >> n2 >> p2 >> m2;
		vector<vector<psi>> t2(n2);
		for(int i=0;i<m2;++i){
			int a, b;
			string s;
			cin >> a >> s >> b;
			t2[a].push_back(psi(s,b));
		}
	
		bool ok = false;
		pii deb(0,0), fin(p1, p2);
		unordered_set<pii, pair_hash> visit;
		queue<piii> q;
		q.push(piii(deb, 0));
		visit.insert(deb);
		while(!q.empty()){
			pii curr = q.front().first;
			int d = q.front().second;
			q.pop();

			if(curr == fin){
				ok = true;
				cout << d << '\n';
				break;
			}

			for(const psi& v1 : t1[curr.first])
				for(const psi& v2 :t2[curr.second])
					if(v1.first == v2.first && visit.find(pii(v1.second, v2.second))==end(visit)){
						q.push(piii(pii(v1.second, v2.second), d+1));
						visit.insert(pii(v1.second, v2.second));
					}
		}

		if(!ok)
			cout << -1 << '\n';
	}
}