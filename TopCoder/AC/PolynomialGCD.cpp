#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

const int MOD = 1000000007;

int aux(const string& s, int p) {
	//cerr << s << ' ' << p << endl;
	int res = 1000000000;
	for(int i=0;i<p;++i) {
		string ss = "";
		int curr = 0;
		for(size_t j=i;j<s.size();j+=p) {
			ss += s[j];
			curr += s[j] - '0';
		}
		if(ss.size() >= p)
			curr += aux(ss, p);
		res = min(res, curr);
	}
	return res;
}

class PolynomialGCD {
	public:
	int gcd(string s) {
		int n = s.size();
		vector<int> prime;
		vector<bool> p(n+1, true);
		p[0] = p[1] = false;
		for(int i=0;i<=n;++i)
			if(p[i]) {
				prime.push_back(i);
				for(int j = i+i;j<=n;j+=i)
					p[j] = false;
				}

		ll res = 1;
		for(int pp:prime){
			int tmp = aux(s, pp);
			while (tmp--) {
				res = (res*pp)%MOD;
			}
		}
		return res;
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "111"; int Arg1 = 6; verify_case(0, Arg1, gcd(Arg0)); }
	void test_case_1() { string Arg0 = "00000"; int Arg1 = 1; verify_case(1, Arg1, gcd(Arg0)); }
	void test_case_2() { string Arg0 = "2014"; int Arg1 = 16; verify_case(2, Arg1, gcd(Arg0)); }
	void test_case_3() { string Arg0 = "31415926535"; int Arg1 = 659897170; verify_case(3, Arg1, gcd(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PolynomialGCD().run_test(-1);
}
// END CUT HERE
