#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;
	for(int icase = 1; icase <= T; ++ icase) {
		cout << "Case #" << icase << ": ";
		int S;
		cin >> S;
		vector<int> t(S+1);
		for(int i = 0; i < S+1; ++i) {
			char c;
			cin >> c;
			t[i] = c - '0';
		}
		int res = 0;
		int curr = 0;
		for(int i = 0; i < S+1; ++i) {
			if(curr < i) {
				res += i-curr;
				curr = i;
			}
			curr += t[i];
		}
		cout << res << '\n';
	}
}