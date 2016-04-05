#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;



class CampLunch {
	public:
	int count(int N, int M, vector <string> a) {
		//compute #fill
		vector<int> fill(1<<M,0);
		for(int i=0;i<(1<<(M-1));++i) 
			if((i&(i<<1)) == 0) {
				int x = (i|(i<<1));
				for(int j=0;j<(1<<M);++j)
					if((x&j)==0)
						++fill[j];
			}


		vector<vector<ll>> dp(N+1,vector<ll>(1<<M, 0));
		dp[0][0] = 1;
		for(int i=0;i<N;++i) {
			vector<int> convert(1<<M,0);
			vector<int> pos(M, 0);
			for(int j=0;j<M;++j)
				pos[a[i][j] - 'A'] = (1<<j);

			for(int j=0;j<(1<<M);++j)
				for(int k=0;k<M;++k) {
					if(j&(1<<k))
						convert[j] += pos[k];
			}


			for(int j=0;j<(1<<M);++j) {
				if(dp[i][j] == 0) continue;
				dp[i][j] %= MOD;
				int kmax = (1<<M) - 1 - j;
				int k = kmax;
				while(true) {
					dp[i+1][k] += dp[i][j] * fill[convert[j|k]];
					if(k==0) break;
					k=((k-1)&kmax);
				}
			}

		}

		return dp[N][0] % MOD;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; string Arr2[] = {"AB","AB"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; string Arr2[] = {"ABC","ABC"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 22; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 3; string Arr2[] = {"ABC","BAC"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 21; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 1; string Arr2[] = {"A"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 10; string Arr2[] = {"ABDEFHIGJC"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 89; verify_case(4, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 16; int Arg1 = 16; string Arr2[] = {"ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 950052677; verify_case(5, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CampLunch().run_test(-1);
}
// END CUT HERE
