#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

class BoardEscape {
	public:
	string findWinner(vector <string> s, int k) {
		vector<int> dx{1,0,-1,0};
        vector<int> dy{0,1,0,-1};
        
        const int K = 100;
        if (k>K) {
            k = k%2 + K - 2;
        }
        
        int n = s.size();
        int m = s[0].size();
        
        vector<vector<vector<int>>> nim (K, vector<vector<int>>(n, vector<int>(m, 0)));
        
        for (int t=1;t<K;++t)
            for (int i=0;i<n;++i)
                for (int j=0;j<m;++j) {
                    if (s[i][j] == 'E')
                        continue;
                    vector<bool> seen (K, false);
                    for(int d=0;d<4;++d) {
                        int nx = i+dx[d];
                        int ny = j+dy[d];
                        if(nx<0 || ny < 0 || nx >= n || ny >= m || s[nx][ny] == '#')
                            continue;
                        seen[nim[t-1][nx][ny]] = true;
                    }

                    int mini = 0;
                    while(seen[mini])
                        ++mini;
                    nim[t][i][j] = mini;
                }
        
        int winner = 0;
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j) {
                if (s[i][j] == 'T')
                    winner ^= nim[k][i][j];
            }
        
        return  (winner?"Alice":"Bob");

	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"TE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; string Arg2 = "Alice"; verify_case(0, Arg2, findWinner(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"E#E",
 "#T#",
 "E#E"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000; string Arg2 = "Bob"; verify_case(1, Arg2, findWinner(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"T.T.T.",
 ".E.E.E"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; string Arg2 = "Alice"; verify_case(2, Arg2, findWinner(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"TTE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; string Arg2 = "Alice"; verify_case(3, Arg2, findWinner(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"..........................",
 "......TTT..TTT..T...T.....",
 ".....T.....T..T.TT.TT.....",
 "......TTT..TTT..T.T.T.....",
 ".........T.T.T..T...T.....",
 "......TTT..T..T.T...T.....",
 "..........................",
 "...E#E#E#E#E#E#E#E#E#E#...",
 "..........................",
 "......TTT..TTT...TTT......",
 ".....T........T.T.........",
 "......TTT.....T..TTT......",
 ".....T...T...T..T...T.....",
 "......TTT....T...TTT......",
 "..........................",
 "...#E#E#E#E#E#E#E#E#E#E...",
 "..........................",
 "....TT...T...T..T.TTT.T...",
 "...T.....T...T..T.T...T...",
 "...T.TT..T...TTTT.TT..T...",
 "...T..T..T...T..T.T.......",
 "....TT...TTT.T..T.T...T...",
 ".........................."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 987654321; string Arg2 = "Bob"; verify_case(4, Arg2, findWinner(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BoardEscape().run_test(-1);
}
// END CUT HERE
