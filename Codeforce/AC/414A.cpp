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
	int n, k;
	cin >> n >> k;
	int couple = n/2;
	if(k<couple || (couple==0 && k>0)){
		cout << "-1";
		return 0;
	}

	int first = k-couple+1;
	int curr = 2*first+1;
	if(couple>0)
		cout << first << ' ' << 2*first;
	for(int i=1;i<couple;++i){
		cout << ' ' << curr << ' ' << curr+1;
		curr += 2;
	}
	if(n%2==1){
		if(couple>0)
			cout << ' ';
		cout << curr;
	}

}