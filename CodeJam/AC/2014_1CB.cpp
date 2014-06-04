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

const ll MOD = 1000000007;

void dfs(char c, set<char>& visited, map<char, vector<char>>& g, map<char,vector<char>>& p){
	visited.insert(c);
	for(char v:g[c])
		if(visited.find(v)==end(visited))
			dfs(v,visited,g,p);
	for(char v:p[c])
		if(visited.find(v)==end(visited))
			dfs(v,visited,g,p);
}

bool impossibleMid(const vector<string>& t){
	set<char> mid;
	set<char> df;
	for(const string& s:t){
		df.insert(s[0]);
		df.insert(s.back());
	}

	for(const string& s:t){
		if(s.size()>2 && s[0]==s.back())
			return true;
		for(int i=1;i<int(s.size())-1;++i){
			char c = s[i];
			if(df.find(c)!=end(df)) return true;
			if(mid.find(c)!=end(mid)) return true;
			mid.insert(c);
		}
	}

	return false;
}

void nodoublon(const string& s, string& ss){
	int curr=0;
	char c;
	while(curr<int(s.size())){
		c = s[curr];
		while(curr<int(s.size()) && s[curr]==c) ++curr;
		ss += c;
	}
}

bool noPath(const map<char, vector<char>>& m){
	for(auto& p:m)
		if(p.second.size()>1)
			return true;

	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	for(int icase = 1;icase<=T;++icase){
		cout << "Case #" << icase << ": ";
		int n;
		cin >> n;
		vector<string> t(n);
		for(int i=0;i<n;++i){
			string s;
			cin >> s;
			nodoublon(s, t[i]);
		}

		if(impossibleMid(t)){
			cout << 0 << '\n';
			continue;
		}
		for(int i=0;i<n;++i){
			ostringstream s;
			s << t[i][0] << t[i].back();
			t[i] = s.str();
		}
		
		for(auto& s:t)
			cerr << s << endl;

		map<char, vector<char>> g;
		map<char, vector<char>> p;
		for(const string& s:t){
			g[s[0]];g[s[1]];p[s[0]];p[s[1]];
			if(s[0]==s[1]) continue;
			g[s[0]].push_back(s[1]);
			p[s[1]].push_back(s[0]);
		}

		if(noPath(g) || noPath(p)){
			cout << 0 << '\n';
			continue;
		}

		ll nbpath=0;
		ll nbvertex=0;
		ll nbedge=0;
		for(auto& pp:g){
			++nbvertex;
			nbedge+=pp.second.size();
		}

		set<char> visited;
		for(auto& pp:g){
			if(visited.find(pp.first)==end(visited)){
				dfs(pp.first, visited, g, p);
				++nbpath;
			}
		}

		cerr << "nbpath " << nbpath << endl;
		cerr << "nbvertex " << nbvertex << endl;
		cerr << "nbedge " << nbedge << endl;
		
		if(nbvertex-nbedge!=nbpath){
			cout << 0 << '\n';
			continue;
		}

		ll res = 1;
		for(ll i=1;i<=nbpath;++i)
			res = (res*i)%MOD;

		for(auto& pp:g){
			char curr = pp.first;
			ll nbc = 0;
			for(const string& s:t)
				if(s[0]==curr && s[1]==curr)
					++nbc;
			for(ll i=1;i<=nbc;++i)
				res = (res*i)%MOD;
		}

		cout << res << '\n';
	}
}