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

int gcd(int a, int b){
	if(b==0) return a;
	return gcd(b, a%b);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int curr, tmp;
		cin >> curr;
		for(int i=1;i<n;++i){
			cin >> tmp;
			curr = gcd(curr, tmp);
		}
		if(curr==1)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}