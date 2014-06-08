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
	int n, d;
	cin >> n >> d;
	for(int i=0;i<n;++i){
		int tmp;
		cin >> tmp;
		d-=tmp;
	}
	if(d-10*(n-1)<0)
		cout << "-1\n";
	else
		cout << d/5 << '\n';
}