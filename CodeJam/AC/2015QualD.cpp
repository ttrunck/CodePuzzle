#include <iostream>
#include <vector>
#include <string>

using namespace std;

const string possible = "GABRIEL";
const string impossible = "RICHARD";

int main() {
	int T;
	cin >> T;
	for(int icase = 1; icase <= T; ++ icase) {
		cout << "Case #" << icase << ": ";
		int X, R, C;
		cin >> X >> R >> C;
		if((C*R)%X != 0) {
			cout << impossible << '\n';
			continue;
		}

		if (max(C, R) < X) {
			cout << impossible << '\n';
			continue;
		}

		if (X > 2 && min(C,R) <= 1) {
			cout << impossible << '\n';
			continue;
		}

		if (X == 4 && min(C, R) == 2) {
			cout << impossible << '\n';
			continue;
		}	
		
		cout << possible << '\n';
	}
}