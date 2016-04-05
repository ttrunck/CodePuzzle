#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

typedef long long ll;

string s;
const ll inf = 1000000000000000ll;

class LuckySum {
public:
	long long construct(string note) {
		ll mult = 1;
		ll a[16];
		ll b[16];
		ll c[16];

		a[note.size()] = inf;
		b[note.size()] = 0;
		c[note.size()] = inf;

		for(int i=note.size()-1;i>=0;--i) {
			//cerr << a[i+1] << ' ' << b[i+1] << ' ' << c[i+1] << endl;
			switch(note[i]) {
				case '?':
					a[i] = b[i] = c[i] = inf;
					if(a[i+1] != inf) {
						a[i] = min(a[i], 2*mult + a[i+1]);
						b[i] = min(b[i], 9*mult + a[i+1]);
						c[i] = min(c[i], 5*mult + a[i+1]);
					}

					if(b[i+1] != inf) {
						a[i] = min(a[i], mult + b[i+1]);
						b[i] = min(b[i], 8*mult + b[i+1]);
						if(i<note.size()-1)
							c[i] = min(c[i], 4*mult + b[i+1]);
					}

					if(c[i+1] != inf && i<note.size()-1) {
						c[i] = min(c[i], 4*mult + c[i+1]);
					}

				break;
				case '1':
					a[i] = b[i] = c[i] = inf;
					if(b[i+1]!= inf)
						a[i] = mult + b[i+1];
				break;
				case '2':
					a[i] = b[i] = c[i] = inf;
					if(a[i+1] != inf)
					a[i] = 2*mult + a[i+1];
				break;
				case '4':
					a[i] = b[i] = c[i] = inf;
					if(b[i+1] != inf) a[i] = 4*mult + b[i+1];
					if((b[i+1] != inf || c[i+1] != inf) && i<note.size()-1) c[i] = 4*mult + min(b[i+1], c[i+1]);
				break;
				case '5':
					a[i] = b[i] = c[i] = inf;
					if(a[i+1] != inf) {
						a[i] = 5*mult + a[i+1];
						c[i] = 5*mult + a[i+1];
					}
				break;
				case '7':
					a[i] = b[i] = c[i] = inf;
					if((b[i+1] != inf || c[i+1] != inf) && i<note.size()-1) {
						c[i] = 7*mult + min(b[i+1], c[i+1]);
					}
				break;
				case '8':
					a[i] = b[i] = c[i] = inf;
					if(b[i+1] != inf)
						b[i] = 8 * mult + b[i+1];
					if(a[i+1] != inf)
						c[i] = 8*mult + a[i+1];
				break;
				case '9':
					a[i] = b[i] = c[i] = inf;
					if(a[i+1] != inf)
						b[i] = 9*mult + a[i+1];
				break;
				default:
					a[i] = b[i] = c[i] = inf;
			}
			mult *= 10;
		}

		ll res = b[0];
		if(note.size()>=2) res = min(res, c[0]);
		if((note[0] == '1' || note[0] == '?') && note.size()>=2) res = min(res, mult/10+a[1]);
		return (res>= inf)?-1:res;
	}

	// BEGIN CUT HERE
public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "?"; long long Arg1 = 8LL; verify_case(0, Arg1, construct(Arg0)); }
	void test_case_1() { string Arg0 = "?1"; long long Arg1 = 11LL; verify_case(1, Arg1, construct(Arg0)); }
	void test_case_2() { string Arg0 = "4?8"; long long Arg1 = 448LL; verify_case(2, Arg1, construct(Arg0)); }
	void test_case_3() { string Arg0 = "2??"; long long Arg1 = -1LL; verify_case(3, Arg1, construct(Arg0)); }
	void test_case_4() { string Arg0 = "4?4"; long long Arg1 = 454; verify_case(4, Arg1, construct(Arg0)); }

	// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LuckySum().run_test(4);
}
// END CUT HERE
