#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
double n;

double aux(int i, int a, const vector<int>& d, vector<vector<double>>& mem) {
	if(mem[i][a] > -1) return mem[i][a];
	double res = d[i];
	for(int j=0;j<i;++j)
		res += aux(j, a+1, d, mem);
	return mem[i][a] = res / (n-a);
}

class RandomPancakeStack {
	public:
	double expectedDeliciousness(vector <int> d) {
		n = d.size();
		vector<vector<double>> mem(n, vector<double>(n, -1));
		double res = 0;
		for(int i=0;i<n;++i)
			res += aux(i, 0, d, mem);
		return res;
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.6666666666666667; verify_case(0, Arg1, expectedDeliciousness(Arg0)); }
	void test_case_1() { int Arr0[] = {3,6,10,9,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 9.891666666666667; verify_case(1, Arg1, expectedDeliciousness(Arg0)); }
	void test_case_2() { int Arr0[] = {10,9,8,7,6,5,4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 10.999999724426809; verify_case(2, Arg1, expectedDeliciousness(Arg0)); }
	void test_case_3() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 7.901100088183421; verify_case(3, Arg1, expectedDeliciousness(Arg0)); }
	void test_case_4() { int Arr0[] = {2,7,1,8,2,8,1,8,2,8,4,5,90,4,5,2,3,5,60,2,8,74,7,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 19.368705050402465; verify_case(4, Arg1, expectedDeliciousness(Arg0)); }
	void test_case_5() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.718281828459045; verify_case(5, Arg1, expectedDeliciousness(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RandomPancakeStack().run_test(-1);
}
// END CUT HERE
