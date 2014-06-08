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

inline int lowbit(int n){
	return n-((n-1)&n);
}

bool mycomp(int a, int b){
	return lowbit(a)>lowbit(b);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int s, l;
	cin >> s >> l;
	vector<int> t(l);
	for(int i=0;i<l;++i)
		t[i]=i+1;
	sort(begin(t), end(t), mycomp);
	int curr = 0;
	for(int x:t)
		curr += lowbit(x);
	if(curr<s)
		cout << "-1\n";
	else{
		vector<int> res;
		for(int x:t)
			if(curr-lowbit(x)<s)
				res.push_back(x);
			else
				curr-=lowbit(x);
		cout << res.size() << '\n';
		for(int x:res)
			cout << x << ' ';
		cout << '\n';
 	}

}