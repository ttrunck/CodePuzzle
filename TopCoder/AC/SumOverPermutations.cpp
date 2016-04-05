#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
const ll MOD = 1000000007;
const int N = 4005;
vector<ll> fact(N);
vector<ll> invFact(N);

ll c(int k, int n) {
	ll res = ((fact[n] * invFact[k])%MOD)*invFact[n-k];
	return res%MOD;
}

ll powMod(ll x, int n) {
	ll y = 1;
	while (n != 0) {
		if ((n & 1) == 1)
			y = (y * x) % MOD;
		x = (x * x) % MOD;
		n = n >> 1;
	}
	return y;
}

// For p prime, return y such as x*y = 1 [p]
int inv(int x) { return powMod(x, MOD - 2); }

class SumOverPermutations {
	public:
	int findSum(int n) {
		fact[1] = 1;
		invFact[1] = 1;
		for(int i=2;i<N;++i) {
			fact[i] = (fact[i-1]*i)%MOD;
			invFact[i] = inv(fact[i]);
		}

		vector<ll> res(n+1, 0);
		res[1] = n;
		res[2] = 2 * n * (n-1);
		for(int i=3;i<=n;++i) {
			res[i] = (2 * (n-1) * res[i-1])%MOD;
			for(int l = 1;l<i-1;++l) {
				int r = i-1-l;
				res[i] += ((((( (n-2) * res[l])%MOD)*res[r])%MOD)*c(l, l+r))%MOD;
				res[i] %= MOD;
			}
		}
		return res[n];
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 4; verify_case(0, Arg1, findSum(Arg0)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 66; verify_case(1, Arg1, findSum(Arg0)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 58310114; verify_case(2, Arg1, findSum(Arg0)); }
	void test_case_3() { int Arg0 = 3900; int Arg1 = 940560814; verify_case(3, Arg1, findSum(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	SumOverPermutations().run_test(-1);
}
// END CUT HERE
