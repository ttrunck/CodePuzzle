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
	int res = 0;
	int p = 0;
	for(int i=0;i<n;++i){
		int tmp;
		cin >> tmp;
		if(tmp==-1){
			if(p==0)
				++res;
			else
				--p;
		}
		else
			p += tmp;
	}

	cout << res << '\n';
}