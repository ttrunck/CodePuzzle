#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <random>
#include <set>
#include <sstream>
#include <cassert>
#include <iomanip>

using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int nbcase;
	cin >> nbcase;
	for(int icase=1;icase<=nbcase;++icase){
		cout << "Case #" << icase << ": ";
		double c, f, x;
		cin >> c >> f >> x;
		double curr = 2;
		double build = 0;
		double res = x/curr;

		for(;;){
			build += c/curr;
			curr += f;
			double tot = build + x/curr;
			if(tot<res)
				res = tot;
			else
				break;
		}

		cout << fixed << setprecision(7) << res << '\n';
	}
}