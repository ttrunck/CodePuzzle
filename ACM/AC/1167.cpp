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

using namespace std;

typedef long long ll;
typedef pair<char, int> pci;
typedef pair<int, int> pi;

const int ret1 = 2000000001;
const int ret0 = 2000000000;

void print(const map<int, vector<pci>>& g){
	cerr << "Voici le graphe\n";
	for(const auto& x:g){
		cerr << x.first << ": ";
		for(const pci& p:x.second)
			cerr << '(' << p.first << ',' << p.second << ") ";
		cerr << endl;
	}
}

void build(const vector<string>& p, map<int, vector<pci>>& g){
	g[ret1].push_back(pci(' ', ret1));
	g[ret0].push_back(pci(' ', ret0));
	for(int i=0;i<int(p.size());++i){
		istringstream ss(p[i]);
		int dep, fin=-1;
		string inst;
		ss >> dep >> inst;
		if(inst == "RET1")
			g[dep].push_back(pci(' ', ret1));
		else if(inst == "RET0")
			g[dep].push_back(pci(' ', ret0));
		else if(inst == "JMP"){
			ss >> fin;
			g[dep].push_back(pci(' ', fin));
		}
		else{
			assert(inst == "BRTRUE");
			ss >> fin;
			g[dep].push_back(pci('1', fin));
			istringstream s_next(p[i+1]);
			int next;
			s_next >> next;
			g[dep].push_back(pci('0', next));
		}
	}
}

int parcourt(map<int, vector<pci>>& g1, map<int, vector<pci>>& g2){
	pi dep(begin(g1)->first, begin(g2)->first);
	set<pi> visited;
	visited.insert(dep);
	queue<pi> q;
	q.push(dep);

	while(!q.empty()){
		pi curr = q.front();
		q.pop();
		//cerr << curr.first << ' ' << curr.second << endl;
		if(curr.first == ret1 && curr.second == ret0) return 0;
		if(curr.first == ret0 && curr.second == ret1) return 0;

		for(const auto& v1 : g1[curr.first])
			for(const auto& v2 : g2[curr.second]){
				if((v1.first == '0' && v2.first == '1') || (v1.first == '1' && v2.first == '0'))
					continue;
				pi next(v1.second, v2.second);
				if(visited.find(next)!=end(visited))
					continue;
				visited.insert(next);
				q.push(next);
			}
	}
	return 1;
}

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
		int P;
		cin >> P;
		while(P--){
			int n;
			cin >> n;
			cin.ignore();
			map<int, vector<pci>> g1, g2;
			vector<string> p1, p2;
			string s;
			//build g1;
			//label ret1 means return 1
			//label ret0 means return 0
			while(getline(cin, s) && s!="END")
				p1.push_back(s);
			build(p1, g1);

			// for(const auto& s : p1)
			// 	cerr << s << endl;

			//build g2;
			while(getline(cin, s) && s!="END")
				p2.push_back(s);
			build(p2, g2);

			// print(g1);
			// print(g2);

			cout << parcourt(g1, g2) << '\n';

		}
	}
}