#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MOD = 1000000007;
const int N = 1000005;
ll fact[N];
ll invFact[N];

int powMod(ll x, int n) {
	ll y = 1;
	while (n != 0) {
		if ((n & 1) == 1)
			y = (y * x) % MOD;
		x = (x * x) % MOD;
		n = n >> 1;
	}
	return y;
}

int C(int n, int k) {
	ll tmp = (invFact[k] * invFact[n-k])%MOD;
	return (tmp * fact[n])%MOD;
}

class PermutationCounts {
	public:
	int countPermutations(int n, vector <int> pos) {
		fact[0] = fact[1] = 1;
		invFact[0] = invFact[1] = 1;
		for(int i=2;i<N;++i) {
			fact[i] = (fact[i-1]*i)%MOD;
			invFact[i] = (invFact[i-1] * (powMod(i, MOD-2)))%MOD;
		}
		pos.push_back(0);
		pos.push_back(n);
		sort(begin(pos), end(pos));
		int K = pos.size();
		vector<ll> dp(K);
		dp[0] = 1;

		for(int i=1;i<K;++i)
			for(int j=0;j<i;++j) {
				ll tmp = (C(pos[i], pos[j]) * dp[j])%MOD;
				if((i+j)%2 == 0)
					dp[i] = (dp[i] - tmp + MOD)%MOD;
				else
					dp[i] = (dp[i] + tmp)%MOD;
			}

		return dp[K-1];
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arr1[] = {3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; verify_case(0, Arg2, countPermutations(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 13; int Arr1[] = {12,11,10,9,8,7,6,5,4,3,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, countPermutations(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 13; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(2, Arg2, countPermutations(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 9; int Arr1[] = {2,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1421; verify_case(3, Arg2, countPermutations(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 80; int Arr1[] = {31,41,59,26,53,58,9,79,32,3,8,46}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 82650786; verify_case(4, Arg2, countPermutations(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 875; int Arr1[] = {295,311,98,345,420,547,646,734,380,325,608,783,141,65,305,437,769,252,44,
872,123,6,50,507,450,426,343,740,69,695,101,607,597,535,342,307,329,837,803,
237,459,444,498,15,712,134,473,14,715,223,787,192,710,750,193,293,242,652,
212,580,545,488,506,533,774,460,285,534,350,210,559,805,686,67,159,541,706,
514,657,801,373,754,310,800,589,736,863,675,254,283,604,27,628,103,81,235,
677,461,609,30,581,75,756,688,262,563,679,21,217,515,836,868,13,728,717,
309,267,767,259,414,332,744,129,859,4,179,632,415,278,812,79,77,784,573,433,
865,407,121,477,567,790,127,593,57,674,114,239,599,552,738}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 169176190; verify_case(5, Arg2, countPermutations(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PermutationCounts().run_test(-1);
}
// END CUT HERE
