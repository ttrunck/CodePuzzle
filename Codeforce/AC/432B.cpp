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
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	for(int i=0;i<n;++i)
		cin >> x[i] >> y[i];

	map<int, int> chome, caway;
	for(auto elt:x)
		chome[elt]++;
	for(auto elt:y)
		caway[elt]++;

	for(int i=0;i<n;++i){
		int home = n-1;
		home += chome[y[i]];
		cout << home << ' ' << 2*(n-1)-home << '\n';
	}  
}