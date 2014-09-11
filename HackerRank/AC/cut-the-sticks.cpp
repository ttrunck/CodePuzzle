#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> t(n);
	for(int i=0;i<n;++i)
		cin >> t[i];
	sort(begin(t), end(t));
	int curr = 0;
	do{
		cout << n-curr << '\n';
		++curr;
		while(curr<n && t[curr]==t[curr-1]) ++curr;
	}while(curr<n);
}