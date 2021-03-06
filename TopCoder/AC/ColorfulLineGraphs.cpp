#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

ll powMod(ll a, ll b, ll m) {
	a %= m;
	if(b==0) return 1;
	ll tmp = (a*a)%m;
	tmp = powMod(tmp,b/2,m);
	if(b%2==0)
		return tmp;
	else
		return (a*tmp)%m;
}

class ColorfulLineGraphs {
	public:
	int countWays(long long n, long long k, int m) {
		ll res = 1;
		k %= m;
		for(int i=0;i<m;++i)
			res = (res * (i*(k-1)+k))%m;
		res = powMod(res, n/m, m);
		for(int i=0;i<n%m;++i)
			res = (res * (i*(k-1)+k))%m;
		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 3LL; long long Arg1 = 2LL; int Arg2 = 100000; int Arg3 = 24; verify_case(0, Arg3, countWays(Arg0, Arg1, Arg2)); }
	void test_case_1() { long long Arg0 = 15LL; long long Arg1 = 3LL; int Arg2 = 1000000; int Arg3 = 510625; verify_case(1, Arg3, countWays(Arg0, Arg1, Arg2)); }
	void test_case_2() { long long Arg0 = 100000LL; long long Arg1 = 100000LL; int Arg2 = 999999; int Arg3 = 185185; verify_case(2, Arg3, countWays(Arg0, Arg1, Arg2)); }
	void test_case_3() { long long Arg0 = 1000000000000LL; long long Arg1 = 6LL; int Arg2 = 1000000; int Arg3 = 109376; verify_case(3, Arg3, countWays(Arg0, Arg1, Arg2)); }
	void test_case_4() { long long Arg0 = 5000LL; long long Arg1 = 1000000000000LL; int Arg2 = 314159; int Arg3 = 202996; verify_case(4, Arg3, countWays(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ColorfulLineGraphs().run_test(-1);
}
// END CUT HERE
