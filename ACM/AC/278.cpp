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
	int T;
	cin >> T;
	while(T--){
		char c;
		int n, m;
		cin >> c >> n >> m;
		if(c=='r')
			cout << min(n, m) << '\n';
		else if(c=='K')
			cout << ((n+1)/2)*((m+1)/2) << '\n';
		else if(c=='Q')
			cout << min(n, m) << '\n';
		else
			cout << ((n+1)/2)*((m+1)/2) + (n/2)*(m/2) << '\n';
	}
}