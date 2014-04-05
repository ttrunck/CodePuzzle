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

const int INF=numeric_limits<int>::max();

typedef long long ll;

struct triple{
	int x,y,c;
	triple(int a=0,int b=0, int cc=0){
		x=a;
		y=b;
		c=cc;
	}
};

int cost(int d, int f, const vector<triple>& t){
	int res=0;
	int xc=0, yc=0;
	for(int i=d;i<=f;++i){
		res += abs(xc-t[i].x) + abs(yc-t[i].y);
		xc = t[i].x;
		yc = t[i].y;
	}
	res += xc + yc;
	return res;
}

int best(int C, int n, vector<int>& mem, const vector<triple>& t){
	if(n<0) return 0;
	if(mem[n]!=-1) return mem[n];
	int res=INF;

	int c=t[n].c;
	int curr=n;
	while(c<=C && curr>=0){
		res = min(res, cost(curr, n, t)+best(C, curr-1, mem, t));
		--curr;
		c+=t[curr].c;
	}
	return mem[n]=res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int nbcase;
	bool first=true;
	cin >> nbcase;
	while(nbcase--){
		if(!first)
			cout << '\n';
		first = false;
		int C;
		int n;
		cin >> C >> n;
		vector<triple> t(n);
		for(int i=0;i<n;++i)
			cin >> t[i].x >> t[i].y >> t[i].c;

		vector<int> mem(n, -1);
		for(int i=0;i<n;++i)
			best(C, i, mem, t);
		cout << best(C, n-1, mem, t) << '\n';
	}
}