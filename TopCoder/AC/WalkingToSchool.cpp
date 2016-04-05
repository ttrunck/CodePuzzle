#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

class WalkingToSchool {
	public:
	string canWalkExactly(int N, vector <int> from, vector <int> to) {
		int M = from.size();
		vector<vector<int>> g(N);
		for(int i=0;i<M;++i)
			g[from[i]].push_back(to[i]);

		vector<vector<bool>> dp1(4*N, vector<bool>(N, false));
		vector<vector<bool>> dp2(4*N, vector<bool>(N, false));

		dp1[0][0] = true;
		dp2[0][1] = true;

		for(int i=0;i<4*N - 1;++i)
			for(int j=0;j<N;++j) {
				if(dp1[i][j])
					for(int x:g[j])
						dp1[i+1][x] = true;

				if(dp2[i][j])
					for(int x:g[j])
						dp2[i+1][x] = true;
			}

			int d = 0;

			for(int i=0;i<4*N;++i)
				if (dp1[i][1])
					for(int j=0;j<4*N;++j)
						if (dp2[j][0])
							d = gcd(d, i+j);

			if (d == 1)
				return "Freedom";
			return "Chores";
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Chores"; verify_case(0, Arg3, canWalkExactly(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = {0, 1, 1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 0, 2, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Freedom"; verify_case(1, Arg3, canWalkExactly(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arr1[] = {0, 2, 2, 3, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 0, 3, 0, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Chores"; verify_case(2, Arg3, canWalkExactly(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 10; int Arr1[] = {0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 5, 5, 5, 6, 6, 6, 7, 8, 9, 9, 9, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4, 5, 6, 7, 9, 4, 6, 0, 1, 3, 8, 4, 6, 1, 4, 8, 1, 7, 8, 1, 4, 2, 5, 6, 8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Chores"; verify_case(3, Arg3, canWalkExactly(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 8; int Arr1[] = {0, 1, 4, 6, 7, 5, 2, 3, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 4, 6, 7, 5, 2, 3, 0, 7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Freedom"; verify_case(4, Arg3, canWalkExactly(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 2000; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); string Arg3 = "Chores"; verify_case(5, Arg3, canWalkExactly(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	WalkingToSchool().run_test(-1);
}
// END CUT HERE
