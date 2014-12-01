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

const int N = 2000001;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	set<int> nombres;
	vector<int> pred(N, 0);
	for(int i=0;i<n;++i){
		int tmp;
		cin >> tmp;
		nombres.insert(tmp);
		pred[tmp] = tmp;
	}

	int curr = 0;
	for(int i = 0; i< N; ++i)
		if(pred[i] != 0)
			curr = pred[i];
		else
			pred[i] = curr;

	int res = 0;

	for(int i : nombres)
		for(int j = i+i; j < N; j += i){
			res = max(res,pred[j-1]%i);
		}
	cout << res << '\n';

}