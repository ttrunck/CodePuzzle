#include<sstream>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

bool ok(int app, int pear, int empty, int a, int p, int e, int K){
    if(app<p+e) return false;
    if(p>0 && empty==0 && e==0) return false;
    if(p+p+e>K) return false; 

    return true;
}

 class UniformBoard
        { 
        public: 
        int getBoard(vector <string> board, int K) 
            { 
                int n=board.size(), m=board[0].size();
                int app=0, pear=0, empty=0;
                for(int i=0;i<n;++i)
                    for(int j=0;j<m;++j){
                        if(board[i][j] == 'A') ++app;
                        if(board[i][j] == 'P') ++pear;
                        if(board[i][j] == '.') ++empty;
                    }
                int res = 0;

                for(int x1=0;x1<n;++x1)
                    for(int y1=0;y1<m;++y1)
                        for(int x2=0;x2<n;++x2)
                            for(int y2=0;y2<m;++y2){
                                int a=0, p=0,e=0;
                                for(int i=x1;i<=x2;++i)
                                    for(int j=y1;j<=y2;++j){
                                        if(board[i][j] == 'A') ++a;
                                        if(board[i][j] == 'P') ++p;
                                        if(board[i][j] == '.') ++e;
                                    }
                                if(ok(app-a, pear-p, empty-e, a, p, e, K))
                                    res = max(res, a+p+e);
                            }


                return res;
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"AP",
 ".A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; verify_case(0, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"AP",
 ".A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(1, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"PPP",
 "APA",
 "A.P"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(2, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"AAA",
 "PPP",
 "AAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 3; verify_case(3, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 0; verify_case(4, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"PPAAPA..AP",
 "PPA.APAP..",
 "..P.AA.PPP",
 "P.P..APAA.",
 "P.P..P.APA",
 "PPA..AP.AA",
 "APP..AAPAA",
 "P.P.AP...P",
 ".P.A.PAPPA",
 "..PAPAP..P"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 15; verify_case(5, Arg2, getBoard(Arg0, Arg1)); }

// END CUT HERE
 
        }; 

    // BEGIN CUT HERE 
    int main()
        {
        UniformBoard ___test; 
        ___test.run_test(-1); 
        } 
    // END CUT HERE 
