#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

const int MOD = 1000000007;

int powMod(ll a, int b) {
	ll res = 1;
	while(b) {
		if(b%2)
			res = (res*a)%MOD;
		a = (a*a)%MOD;
		b/=2;
	}
	return res;
}

class LineMST {
	public:
	int count(int N, int L) {
		vector<vector<ll>> dp(N, vector<ll>(L+1, 0));

		for(int i=0;i<=L;++i)
			dp[0][i] = 1;

		for(int x=1;x<N;++x)
			for(int j=1;j<=L;++j) {
				dp[x][j] = dp[x][j-1];
				for(int i=0;i<x;++i) {
					dp[x][j] += ((dp[i][j-1] * dp[x-i-1][j])%MOD)*powMod(L-j+1, (i+1)*(x-i)-1);
					dp[x][j] %= MOD;
				}
			}

		ll res = dp[N-1][L];
		for(int i=3;i<=N;++i)
			res = (res*i)%MOD;
		return res;
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 15; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 10; int Arg2 = 10; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 3; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 8; int Arg1 = 41; int Arg2 = 655468587; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 200; int Arg1 = 200; int Arg2 = 152699064; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LineMST().run_test(-1);
}
// END CUT HERE
