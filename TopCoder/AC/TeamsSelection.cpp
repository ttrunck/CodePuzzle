#include<sstream>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

 class TeamsSelection
        { 
        public: 
        string simulate(vector <int> preference1, vector <int> preference2) 
            { 
	      int N=preference1.size();
	      string res(N,' ');
	      int curr1=0, curr2=0;
	      while(curr1<N && curr2<N){
		while(curr1<N && res[preference1[curr1]-1]!=' ')curr1++;
		if(curr1<N)
		  res[preference1[curr1]-1]='1';
		while(curr2<N && res[preference2[curr2]-1]!=' ')curr2++;
		if(curr2<N)
		  res[preference2[curr2]-1]='2';
	      }
	      return res;
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "1212"; verify_case(0, Arg2, simulate(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 3, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "211"; verify_case(1, Arg2, simulate(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {6, 1, 5, 2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 6, 3, 4, 5, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "212211"; verify_case(2, Arg2, simulate(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {8, 7, 1, 2, 4, 5, 6, 3, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 2, 4, 8, 1, 5, 9, 6, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "121121212"; verify_case(3, Arg2, simulate(Arg0, Arg1)); }

// END CUT HERE
 
        }; 

    // BEGIN CUT HERE 
    int main()
        {
        TeamsSelection ___test; 
        ___test.run_test(-1); 
        } 
    // END CUT HERE 
