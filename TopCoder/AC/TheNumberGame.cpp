#include<sstream>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

bool match(const string & s, const string & t){
  int n=s.size();
  for(int i=0;i+n<=int(t.size());++i)
    if(s==t.substr(i,n))
      return true;

    return false;
}

 class TheNumberGame
        { 
        public: 
        string determineOutcome(int A, int B) 
            { 
	      ostringstream aa;
	      aa << A;
	      string a=aa.str();
	      ostringstream bb;
	      bb << B;
	      string b=bb.str();
	      string reva(a);
	      reverse(reva.begin(), reva.end());
	      string res;
	      if(match(b,a) || match(b,reva))
		res="Manao wins";
	      else
		res="Manao loses";
	      return res;
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 45; int Arg1 = 4; string Arg2 = "Manao wins"; verify_case(0, Arg2, determineOutcome(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 45; int Arg1 = 5; string Arg2 = "Manao wins"; verify_case(1, Arg2, determineOutcome(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 99; int Arg1 = 123; string Arg2 = "Manao loses"; verify_case(2, Arg2, determineOutcome(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2356236; int Arg1 = 5666; string Arg2 = "Manao loses"; verify_case(3, Arg2, determineOutcome(Arg0, Arg1)); }

// END CUT HERE
 
        }; 

    // BEGIN CUT HERE 
    int main()
        {
        TheNumberGame ___test; 
        ___test.run_test(-1); 
        } 
    // END CUT HERE 
