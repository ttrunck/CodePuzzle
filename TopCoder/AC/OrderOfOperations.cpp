#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

class OrderOfOperations {
	public:
	int minTime(vector <string> s) {
		int n = s.size(), m = s[0].size();
		vector<int> t(n, 0);
		for(int i = 0;i<n;++i)
			for(int j=0;j<m;++j)
				if(s[i][j] == '1')
					t[i] |= 1<<j;

			int dest = 0;
			for(int x:t)
				dest |= x;

			const int INF = m*m + 1;
			vector<int> d(1<<m, INF);
			d[0] = 0;

			for(int j=0;j<(1<<m);++j)
				for(int i=0;i<n;++i){
					int tmp = __builtin_popcount((t[i]|j) - j);
					d[j|t[i]] = min(d[j|t[i]], d[j] + tmp*tmp);
				}

			return d[dest];
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
 "111",
 "001",
 "010"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, minTime(Arg0)); }
	void test_case_1() { string Arr0[] = {
 "11101",
 "00111",
 "10101",
 "00000",
 "11000"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(1, Arg1, minTime(Arg0)); }
	void test_case_2() { string Arr0[] = {
  "11111111111111111111"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 400; verify_case(2, Arg1, minTime(Arg0)); }
	void test_case_3() { string Arr0[] = {
  "1000",
  "1100",
  "1110"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, minTime(Arg0)); }
	void test_case_4() { string Arr0[] = {
  "111",
  "111",
  "110",
  "100"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(4, Arg1, minTime(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	OrderOfOperations().run_test(-1);
}
// END CUT HERE
