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
		int n, a, b;
		cin >> n >> a >> b;
		set<int> res;
		res.insert(0);
		while(--n){
			set<int> tmp;
			for(int x:res){
				tmp.insert(x+a);
				tmp.insert(x+b);
			}
			res.clear();
			for(int x:tmp)
				res.insert(x);
		}
		for(int x:res)
			cout << x << ' ';
		cout << '\n';
	}
}