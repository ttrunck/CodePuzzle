#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

map<pair<set<int>, pi>, ll> mem;

ll aux(set<int> s, int l, int n){

	if(l==0){
		return (s.size()==10?1:0);
	}

	pair<set<int>, pi> elt{s, pi{l, n}};
	auto it = mem.find(elt);
	if(it!=end(mem)) return it->second;

	ll res = 0;
	if(n>0){
		set<int> ss{s};
		ss.insert(n-1);
		res+=aux(ss, l-1, n-1);
	}
	if(n<9){
		set<int> ss{s};
		ss.insert(n+1);
		res+=aux(ss, l-1, n+1);
	}

	return mem[elt]=res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ll res = 0;
	for(int l=0;l<40;++l)
	for(int i=1;i<10;++i)
		res += aux(set<int>{i}, l, i);
	cout << res << '\n';
}