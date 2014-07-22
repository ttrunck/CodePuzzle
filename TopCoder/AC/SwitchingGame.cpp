#include<sstream>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

 class SwitchingGame
        { 
        public: 
        int timeToWin(vector <string> states) 
            { 
            	int n = states[0].size();
            	int res = 0;
            	string curr(n, '-');
            	for(const string& s:states){
	            	bool plus = false, minus = false;
    	        	for(int i=0;i<n;++i)
    	        		if(curr[i] == '-' && s[i] == '+'){
    	        			plus = true;
    	        			++res;
    	        			break;
    	        		}
    	        	for(int i=0;i<n;++i)
    	        		if(curr[i] == '+' && s[i] == '-'){
    	        			minus = true;
    	        			++res;
    	        			break;
    	        		}

    	        	for(int i=0;i<n;++i){
    	        		if(s[i] == '+' || s[i] == '-')
    	        			curr[i] = s[i];
    	        		else if(curr[i]=='?' || (curr[i]=='+' && minus) || (curr[i]=='-' && plus))
    	        			curr[i] = '?'; 
    	        	}
    	        	++res;

    	        }

            	return res;
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"++--",
 "--++"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, timeToWin(Arg0)); }
	void test_case_1() { string Arr0[] = {"+-++",
 "+-++"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, timeToWin(Arg0)); }
	void test_case_2() { string Arr0[] = {"++",
 "+?",
 "?+",
 "++"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(2, Arg1, timeToWin(Arg0)); }
	void test_case_3() { string Arr0[] = {"+", 
 "?",
 "?",
 "?",
 "-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(3, Arg1, timeToWin(Arg0)); }
	void test_case_4() { string Arr0[] = {"+??+++",
 "++??+-",
 "?++??+",
 "?-+-??",
 "??+?++",
 "++-?+?",
 "?++?-+",
 "?--+++",
 "-??-?+"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; verify_case(4, Arg1, timeToWin(Arg0)); }

// END CUT HERE
 
        }; 

    // BEGIN CUT HERE 
    int main()
        {
        SwitchingGame ___test; 
        ___test.run_test(-1); 
        } 
    // END CUT HERE 
