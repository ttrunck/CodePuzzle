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

int is_last(int N, const vector<int>& p){
	int survivor = 0;
	for(int i=0;i<N;++i){
		survivor = (survivor + p[N-i-1])%(i+1);
	}

	return survivor+1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	vector<bool> p(50000, true);
	vector<int> prime;
	p[0] = p[1] = false;
	for(int i=2;i<50000;++i)
		if(p[i]){
			prime.push_back(i);
			for(int j=i+i;j<50000;j+=i)
				p[j] = false;
		}

	int n;
	while(cin >> n && n)
		cout << is_last(n, prime) << '\n';

}