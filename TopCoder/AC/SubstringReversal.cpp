#include<sstream>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

char mini(int x, int n, const string& S){
    char res = S[x];
    for(int i=x;i<n;++i)
        res = min(res, S[i]);
    return res;
}

bool comp(int y, int y2, int x, const string& S){
    int i = y2;
    for(int j=y;j>=x;--j){
        if(S[j]<S[i])
            return false;
        else if(S[j]>S[i])
            return true;
        --i;
    }
    for(int j=y+1;j<=y2;++j){
        if(S[j]<S[i])
            return false;
        else if(S[j]>S[i])
            return true;
        --i;
    }
    return false;
}

 class SubstringReversal
        { 
        public: 
        vector <int> solve(string S) 
            { 
                int x = 0, y = 0;
                int n = S.size();

                bool trie = true;
                for(int i=0;i<n-1;++i)
                    if(S[i]>S[i+1])
                        trie = false;
                if(!trie){
                    while(x<n && S[x]==mini(x, n, S))
                        ++x;                   
                    y = x+1;
                    for(int i=x+1;i<n;++i)
                        if(comp(y, i, x, S))
                            y=i;
                }
                vector<int> res{x, y};
                return res;
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "abdc"; int Arr1[] = {2, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { string Arg0 = "aabbcc"; int Arr1[] = {0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { string Arg0 = "misof"; int Arr1[] = {0, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { string Arg0 = "ivan"; int Arr1[] = {0, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, solve(Arg0)); }
	void test_case_4() { string Arg0 = "xazxa"; int Arr1[] = {0, 4 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, solve(Arg0)); }

// END CUT HERE
 
        }; 

    // BEGIN CUT HERE 
    int main()
        {
        SubstringReversal ___test; 
        ___test.run_test(-1); 
        } 
    // END CUT HERE 
