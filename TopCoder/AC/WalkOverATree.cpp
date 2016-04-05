#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

int dfs(int x, const vector<vector<int>>& t) {
	int res = -1;
	for(int v : t[x])
		res = max(res, dfs(v, t));
	return 1 + res;
}

class WalkOverATree {
	public:
	int maxNodesVisited(vector <int> parent, int L) {
		int n = parent.size();
		vector<vector<int>> t(n+1);
		for(int i=0;i<n;++i)
			t[parent[i]].push_back(i+1);
		int p = dfs(0, t);
		int d = min(p, L);
		return min(n+1, d + (L-d)/2 + 1);
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; verify_case(0, Arg2, maxNodesVisited(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 3; verify_case(1, Arg2, maxNodesVisited(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, 1, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(2, Arg2, maxNodesVisited(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0,0,0,0,2,4,2,3,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(3, Arg2, maxNodesVisited(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0,0,1,2,3,2,3,1,3,0,1,8,6,8,0,5,15,0,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 5; verify_case(4, Arg2, maxNodesVisited(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {0,0,0,1,1,3,5,1,4,5,2,2,10,5,10,10,11,13,8,3,18,15,20,20,23,8,11,26,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 26; int Arg2 = 17; verify_case(5, Arg2, maxNodesVisited(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {0, 0, 2, 0}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; int Arg2 = 5; verify_case(6, Arg2, maxNodesVisited(Arg0, Arg1)); }
	void test_case_7() { int Arr0[] = {0, 0, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 4; verify_case(7, Arg2, maxNodesVisited(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	WalkOverATree().run_test(-1);
}
// END CUT HERE
