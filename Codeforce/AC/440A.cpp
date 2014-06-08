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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<bool> t(n, false);
	for(int i=0;i<n-1;++i){
		int tmp;
		cin >> tmp;
		t[tmp-1] = true;
	}
	int res=0;
	while(t[res])++res;
	cout << res+1 << '\n';
}