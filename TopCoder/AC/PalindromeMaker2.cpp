#include<sstream>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

 class PalindromeMaker2
        { 
        public: 
        string make(string baseString) 
            { 
	      int bonus = int(baseString.size())%2;
	      sort(baseString.begin(), baseString.end());
	      string res = baseString;
	      for(int i=0, j=0;i<int(res.size());){
		if(i+1<int(res.size()) && baseString[i]!=baseString[i+1]){
		  bonus--;
		  if(bonus<0)
		    return "";
		  res[int(res.size())/2]=baseString[i];
		  i++;
		  continue;
		}
		res[j] = baseString[i];
		res[int(res.size())-1-j] = baseString[i];
		i+=2;
		j++;
	      }
	      return res;
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AABB"; string Arg1 = "ABBA"; verify_case(0, Arg1, make(Arg0)); }
	void test_case_1() { string Arg0 = "AAABB"; string Arg1 = "ABABA"; verify_case(1, Arg1, make(Arg0)); }
	void test_case_2() { string Arg0 = "ABACABA"; string Arg1 = "AABCBAA"; verify_case(2, Arg1, make(Arg0)); }
	void test_case_3() { string Arg0 = "ABCD"; string Arg1 = ""; verify_case(3, Arg1, make(Arg0)); }

// END CUT HERE
 
        }; 

    // BEGIN CUT HERE 
    int main()
        {
        PalindromeMaker2 ___test; 
        ___test.run_test(-1); 
        } 
    // END CUT HERE 
