#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll powMod(ll a, ll b, int m) {
	if(b==0) return 1;
	ll tmp = powMod((a*a)%m, b/2,m);
	if(b%2==1)
		tmp = (tmp*a)%m;
	return tmp;
}

class BearPlays {
	public:
	int pileSize(int A, int B, int K) {
		int c = (powMod(2, K, A+B) * A)%(A+B);
		return min(c, A+B-c);
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 7; int Arg2 = 2; int Arg3 = 5; verify_case(0, Arg3, pileSize(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 3; int Arg3 = 0; verify_case(1, Arg3, pileSize(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 6; int Arg2 = 1; int Arg3 = 4; verify_case(2, Arg3, pileSize(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 2263846; int Arg1 = 823749379; int Arg2 = 2000000000; int Arg3 = 281712054; verify_case(3, Arg3, pileSize(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 900000000; int Arg1 = 350000000; int Arg2 = 3; int Arg3 = 300000000; verify_case(4, Arg3, pileSize(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BearPlays().run_test(-1);
}
// END CUT HERE
