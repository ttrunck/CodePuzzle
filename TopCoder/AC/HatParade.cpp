#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pi;

const int MOD = 1000000007;

class HatParade {
	public:
	int getPermutation(vector <int> value, vector <int> sum) {
		ll SUM = 0;
		for(int x:value)
			SUM += x;

		ll left = 0, right = 0;
		vector<bool> ok(value.size(), true);
		ll res = 1;
		for(int i=0;i<int(value.size());++i) {
			if(left > right)
				swap(left, right);
				int id = -1;

				for(int j=0;j<int(value.size());++j)
					if(ok[j] && (sum[j] == left + value[j] || sum[j] == SUM - left)) {
						id = j;
						break;
					}

				if(id == -1) return 0;
				ok[id] = false;
				if(left == right && i != int(value.size()) - 1) {
					res *= 2;
					if(res > MOD)
						res -= MOD;
				}
				left += value[id];
		}

		return res;
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2, 1, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 1, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, getPermutation(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {9, 1, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, getPermutation(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {4, 4, 4, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {16, 16, 8, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(2, Arg2, getPermutation(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 27, 6, 22, 18, 21, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(3, Arg2, getPermutation(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	HatParade().run_test(-1);
}
// END CUT HERE
