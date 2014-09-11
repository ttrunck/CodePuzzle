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
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int n5=n;
		while(n5>=0 && (n5%3!=0 || (n-n5)%5!=0))--n5;
		if(n5<0)
			cout << -1;
		else{
			for(int i=0;i<n5;++i)
				cout << 5;
			for(int i=0;i<n-n5;++i)
				cout << 3;
		}
		cout << '\n';
	}
}