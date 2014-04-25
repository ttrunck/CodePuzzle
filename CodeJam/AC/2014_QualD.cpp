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

const double eps = 1e-7;

int ken(double x, const vector<double>& t, vector<bool>& used){
	int dep = 0;
	while(used[dep]) ++dep;

	int curr = dep;
	while(curr<int(t.size()) && (used[curr] || t[curr]<x))
		++curr;

	if(curr == int(t.size())){
		used[dep] = true;
		return (t[dep]<x)?1:0;
	}
	else{
		used[curr] = true;
		return (t[curr]<x)?1:0;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int nbcase;
	cin >> nbcase;
	for(int icase=1;icase<=nbcase;++icase){
		cout << "Case #" << icase << ": ";

		int n;
		cin >> n;
		vector<double> t1(n), t2(n);
		for(int i=0;i<n;++i)
			cin >> t1[i];
		for(int i=0;i<n;++i)
			cin >> t2[i];

		int war=0, dwar=0;
		sort(begin(t1), end(t1));
		sort(begin(t2), end(t2));

		// cerr << endl;
		// for(auto x:t1)
		// 	cerr << x << ' ';

		// cerr << endl;
		// for(auto x:t2)
		// 	cerr << x << ' ';
		// cerr << endl;

		vector<bool> used(n, false);
		for(double x:t1)
			war += ken(x, t2, used);

		used.assign(n, false);
		int d2=0, f2=n-1;
		for(int i=0;i<n;++i){
			if(t1[i]<t2[d2]){
				dwar += ken(t2[f2]-eps, t2, used);
				--f2;
			}
			else{
				dwar += ken(t2[f2]+eps, t2, used);
				++d2;
			}
		}

		cout << dwar << ' ' << war << '\n';
	}
}