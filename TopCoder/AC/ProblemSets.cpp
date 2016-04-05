#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

bool pos(ll x, long long E, long long EM, long long M, long long MH, long long H) {
	if(x > E + EM)
		return false;
	ll a = min(EM, E + EM - x);
	if(x > MH + H)
		return false;
	ll b = min(MH, H + MH - x);
	if(x > M + a + b)
		return false;
	return true;
}

class ProblemSets {
	public:
	long long maxSets(long long E, long long EM, long long M, long long MH, long long H) {
		ll lo = -1, hi = E + EM + M + MH + H;
		while(lo != hi) {
			ll mid = lo + (hi-lo)/2;
			if(pos(mid, E, EM, M, MH, H))
				lo = mid+1;
			else
				hi = mid;
		}
		if(pos(lo, E, EM, M, MH, H))
			return lo;
		return lo-1;
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 2LL; long long Arg1 = 2LL; long long Arg2 = 1LL; long long Arg3 = 2LL; long long Arg4 = 2LL; long long Arg5 = 3LL; verify_case(0, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { long long Arg0 = 100LL; long long Arg1 = 100LL; long long Arg2 = 100LL; long long Arg3 = 0LL; long long Arg4 = 0LL; long long Arg5 = 0LL; verify_case(1, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { long long Arg0 = 657LL; long long Arg1 = 657LL; long long Arg2 = 657LL; long long Arg3 = 657LL; long long Arg4 = 657LL; long long Arg5 = 1095LL; verify_case(2, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { long long Arg0 = 1LL; long long Arg1 = 2LL; long long Arg2 = 3LL; long long Arg3 = 4LL; long long Arg4 = 5LL; long long Arg5 = 3LL; verify_case(3, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { long long Arg0 = 1000000000000000000LL; long long Arg1 = 1000000000000000000LL; long long Arg2 = 1000000000000000000LL; long long Arg3 = 1000000000000000000LL; long long Arg4 = 1000000000000000000LL; long long Arg5 = 1666666666666666666LL; verify_case(4, Arg5, maxSets(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ProblemSets().run_test(-1);
}
// END CUT HERE
