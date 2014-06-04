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
	int m, n;
	double down, car;
	while(cin >> m >> down >> car >> n && m>=0){
		vector<double> t(m+1, -1);
		for(int i=0;i<n;++i){
			int a;
			double b;
			cin >> a >> b;
			t[a] = b;
		}
		for(int i=1;i<m+1;++i)
			if(t[i]==-1)
				t[i] = t[i-1];
		double owns = car;
		double reb = owns/m;
		car += down;
		car *= (1-t[0]);
		int res = 1;
		while(owns>car){
			//cerr << car << ' ' << owns << '\n';
			owns -= reb;
			car*= (1-t[res]);
			++res;
		}
		--res;
		cout << res << " month" << (res==1?"":"s") << '\n';
	}
}