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
	while(n--){
		string s;
		cin >> s;
		int res=0;
		char c = s[0];
		for(int i=1;i<int(s.size());++i)
			if(s[i]==c)
				++res;
			else
				c=s[i];
		cout << res << '\n';
	}
}