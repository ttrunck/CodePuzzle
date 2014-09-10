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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	
	bool curr = false;
	vector<bool> res(n);
	for(int i=0;i<n;++i){
		res[i] = curr!=(s[i]=='1');

		curr = curr!=res[i];
		if(i-k+1>=0)
			curr = curr!=res[i-k+1];

	}

	for(bool b:res)
		cout << (b?'1':'0');
	cout << '\n';
}