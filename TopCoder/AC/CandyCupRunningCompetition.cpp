#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

ll powMod(ll x, ll n) {
    ll y = 1;
    while (n != 0) {
        if ((n & 1) == 1)
            y = (y * x) % MOD;
        x = (x * x) % MOD;
        n = n >> 1;
    }
    return y;
}

int pere(int x, vector<int>& p){
    if(p[x]==x) return x;
    int px = pere(p[x], p);
    return p[x]=px;
}

 class CandyCupRunningCompetition
        { 
        public: 
        int findMaximum(int N, vector <int> A, vector <int> B) 
            { 
                ll res = 0;
                int M= int(A.size());
                vector<int> p(N,-1);
                for(int i=0;i<N;++i)
                    p[i]=i;

                for(int i=M-1;i>=0;--i){
                    if((pere(A[i], p) == pere(0, p) && pere(B[i], p) == pere(N-1, p))
                        || (pere(A[i], p) == pere(N-1, p) && pere(B[i], p) == pere(0, p)))
                        res = (res + powMod(3, i))%MOD;
                    else if(pere(A[i], p) != pere(B[i], p))
                        p[pere(A[i], p)] = pere(B[i], p);
                }

                return res;
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, findMaximum(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {0,1,0,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,3,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; verify_case(1, Arg3, findMaximum(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(2, Arg3, findMaximum(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 5; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(3, Arg3, findMaximum(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 6; int Arr1[] = {1,1,2,0,4,3,0,1,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,2,3,1,5,5,2,4,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 39; verify_case(4, Arg3, findMaximum(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
        }; 

    // BEGIN CUT HERE 
    int main()
        {
        CandyCupRunningCompetition ___test; 
        ___test.run_test(-1); 
        } 
    // END CUT HERE 
