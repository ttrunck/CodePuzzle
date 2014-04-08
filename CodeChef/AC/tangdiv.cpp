#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <random>
#include <sstream>
#include <cassert>
#include <unordered_set>

using namespace std;

typedef long long ll;

bool ok(const unordered_set<int>& t1, const unordered_set<int>& t2){
	for(int x:t2){
		if(t1.find(x)==end(t1))
			return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--){
		int n, k, p;
		cin >> n >> k >> p;
		unordered_set<int> t1, t2;
		for(int i=0;i<k;++i){
			int a, b;
			cin >> a >> b;
			t1.insert(a-1);
			t1.insert(b%n);
		}
		for(int i=0;i<p;++i){
			int a, b;
			cin >> a >> b;
			t2.insert(a-1);
			t2.insert(b%n);
		}

		if(ok(t1, t2))
			cout << "Yes\n";
		else
			cout << "No\n";

	}
}