#include<sstream>
#include<string>
#include<vector>
#include<iostream>
#include <set>

using namespace std;

 class MyLongCake
        { 
        public: 
        int cut(int n) 
            { 
                set<int> cut;
                for(int i=2;i*i<=n;++i)
                    if(n%i==0){
                        for(int j=i;j<n;j+=i)
                            cut.insert(j);
                        for(int j=n/i;j<n;j+=n/i)
                            cut.insert(j);
                    }
                return cut.size()+1;
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 4; verify_case(0, Arg1, cut(Arg0)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; verify_case(1, Arg1, cut(Arg0)); }
	void test_case_2() { int Arg0 = 15; int Arg1 = 7; verify_case(2, Arg1, cut(Arg0)); }
	void test_case_3() { int Arg0 = 100000; int Arg1 = 60000; verify_case(3, Arg1, cut(Arg0)); }

// END CUT HERE
 
        }; 

    // BEGIN CUT HERE 
    int main()
        {
        MyLongCake ___test; 
        ___test.run_test(-1); 
        } 
    // END CUT HERE 
