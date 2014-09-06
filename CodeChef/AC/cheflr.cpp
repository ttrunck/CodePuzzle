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

const ll MOD = 1000000007;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for(int i=0;i<n;++i){
		string tmp;
		cin >> tmp;
		ll curr = 1;
		for(int i=0;i<int(tmp.size());++i){
			curr *= 2;
			if(i%2==1)
				--curr;
			if(tmp[i] == 'r')
				curr += 2;
			curr = curr%MOD;
		}
		cout << curr << '\n';
	}
}