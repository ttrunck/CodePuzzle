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

int solve(int pos, string& s, int k){
	int maxi = s[pos];
	int x = pos;
	for(int i=pos;i<s.size() && i-pos<=k;++i)
		if(s[i]>maxi){
			maxi=s[i];
			x=i;
		}
	for(int i=x;i>pos;--i)
		swap(s[i], s[i-1]);
	return x-pos;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	int k;
	cin >> s >> k;
	int curr = 0;
	while(curr < s.size() && k){
		k -= solve(curr, s, k);
		++curr;
	}
	cout << s << '\n';
}