#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

typedef long long ll;

map<vector<int>, ll> mem;

ll aux(int l, int n1, int n2, int n3){
	vector<int> par{l, n1, n2, n3};

	if(l==0) return 1;

	auto it = mem.find(par);
	if(it!=end(mem))
		return it->second;

	ll res=0;

	if(10-n1-n2-n3>0)
		res += (10-n1-n2-n3) * aux(l-1, n1+1, n2, n3);
	if(n1>0)
		res += n1 * aux(l-1, n1-1, n2+1, n3);
	if(n2>0)
		res += n2 * aux(l-1, n1, n2-1, n3+1);

	return mem[par] = res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << 9*aux(17, 1, 0 ,0) << '\n';
}