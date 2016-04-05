#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

const int MOD = 1000000007;
const int BILLION = 1000000000;

int powMod(int a, int b) {
	int res = 1;
	while(b) {
		if(b%2)
			res = (res * 1ll * a) % MOD;
		a = (a*1ll*a)%MOD;
		b/=2;
	}
	return res;
}

class BearAttacks {
	public:
	int expectedValue(int N, int R, int A, int B, int M, int LOW, int HIGH) {
		vector<ll> prob(N);
		for(int i=0;i<N;++i)
			prob[i] = powMod(i+1,MOD-2);

		vector<int> p(N, 0);
		for(ll i=1;i<N;++i) {
			R = (A*1ll*R +B) %  M;
			ll MIN = (i-1)*LOW / BILLION;
			ll MAX = (i-1)*HIGH / BILLION;
			p[i] = MIN + (R%(MAX-MIN+1));
		}

		vector<ll> dp(N);
		for(int i=0;i<N;++i)
			dp[i] = prob[i];

		for(int i=(N-1);i>0;--i)
			dp[p[i]] = (dp[p[i]] + dp[i] * prob[p[i]]) % MOD;

		ll res = 0;
		for(int x:prob)
			res = (res + x)%MOD;
		for(int i=1;i<N;++i) {
			res = (res + prob[p[i]] * dp[i])%MOD;
			res = (res + dp[i] *  (dp[p[i]] - (prob[p[i]] * dp[i])%MOD + MOD))%MOD;
		}

		for(int i=2;i<=N;++i)
			res = (res * i) % MOD;
		return res;
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 0; int Arg2 = 2; int Arg3 = 3; int Arg4 = 100; int Arg5 = 938593850; int Arg6 = 1000000000; int Arg7 = 21; verify_case(0, Arg7, expectedValue(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 1; int Arg5 = 0; int Arg6 = 0; int Arg7 = 23; verify_case(1, Arg7, expectedValue(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 303840291; int Arg2 = 848660283; int Arg3 = 395739574; int Arg4 = 950123456; int Arg5 = 0; int Arg6 = 1000000000; int Arg7 = 3856; verify_case(2, Arg7, expectedValue(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 1; int Arg5 = 0; int Arg6 = 0; int Arg7 = 1; verify_case(3, Arg7, expectedValue(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_4() { int Arg0 = 50; int Arg1 = 725842590; int Arg2 = 53523743; int Arg3 = 783815874; int Arg4 = 917800553; int Arg5 = 0; int Arg6 = 1000000000; int Arg7 = 477624210; verify_case(4, Arg7, expectedValue(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BearAttacks().run_test(-1);
}
// END CUT HERE
