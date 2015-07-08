#include <iostream>
#include <vector>


using namespace std;

int f(int x, int n) {
	return (x+n-1)/n - 1;
}

int main() {
	int T;
	cin >> T;
	for (int icase = 1; icase <= T; ++icase) {
		cout << "Case #" << icase << ": ";
		int D;
		cin >> D;
		vector<int> P(D);
		for(int i=0;i<D;++i)
			cin >> P[i];
		int res = 2000;
		for(int i = 1;i<=1000;++i) {
			int malus = 0;
			for(int x : P)
				malus += f(x, i);
			res = min(res, malus + i);
		}
		cout << res << '\n';
	}
}