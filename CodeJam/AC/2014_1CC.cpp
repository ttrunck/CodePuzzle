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
	for(int icase=1;icase<=T;++icase){
		cout << "Case #" << icase << ": ";
		int n;
		cin >> n;
		int score=0;
		for(int i=0;i<n;++i){
			int tmp;
			cin >> tmp;
			if(tmp<=i)
				++score;
		}
		if(score<(500+470)/2)
			cout << "BAD\n";
		else
			cout << "GOOD\n";
	}
}