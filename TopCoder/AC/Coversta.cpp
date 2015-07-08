#include <map>
#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

class Coversta {
	public:
	int N, M, K;
	bool valid(int x, int y) {
		return x>=0 && x<N && y>=0 && y<M;
	}

	int place(vector <string> a, vector <int> x, vector <int> y) {
		N = a.size();
		M = a[0].size();
		K = x.size();
		vector<vector<int>> score(N, vector<int>(M, 0));
		for(int i=0;i<N;++i)
			for(int j=0;j<M;++j)
				for(int k=0;k<K;++k)
					if(valid(i+x[k], j+y[k])) {
						score[i][j] += a[i+x[k]][j+y[k]] - '0';
					}
		priority_queue<int> all_score;
		for(int i = 0;i<N;++i)
			for(int j=0;j<M;++j)
				all_score.push(score[i][j]);

		int res = 0;
		for(int i=0;i<N;++i)
			for(int j=0;j<M;++j) {
				int curr = score[i][j];
				set<pi> touch;

				for(int k1=0;k1<K;++k1)
					for(int k2=0;k2<K;++k2)
						if(valid(i+x[k1], j+y[k1]) && valid(i+x[k1]-x[k2], j+y[k1]-y[k2])) {
							touch.insert({i+x[k1]-x[k2], j+y[k1]-y[k2]});
						}
				
				priority_queue<int> to_remove;
				for(pi p:touch)
					to_remove.push(score[p.first][p.second]);

				for(int k1=0;k1<K;++k1)
					for(int k2=0;k2<K;++k2)
						if(valid(i+x[k1], j+y[k1]) && valid(i+x[k1]-x[k2], j+y[k1]-y[k2])) {
							score[i+x[k1]-x[k2]][j+y[k1]-y[k2]] -= a[i+x[k1]][j+y[k1]] - '0';
						}

				int smax = 0;
				for(pi p:touch)
					smax = max(smax, score[p.first][p.second]);

				vector<int> to_fix;

				while(smax<all_score.top() && !to_remove.empty() && to_remove.top() == all_score.top()) {
					to_fix.push_back(to_remove.top());
					to_remove.pop();
					all_score.pop();
				}

				curr += max(all_score.empty()?0:all_score.top(), smax);

				for(int x:to_fix)
					all_score.push(x);

				for(int k1=0;k1<K;++k1)
					for(int k2=0;k2<K;++k2)
						if(valid(i+x[k1], j+y[k1]) && valid(i+x[k1]-x[k2], j+y[k1]-y[k2])) {
							score[i+x[k1]-x[k2]][j+y[k1]-y[k2]] += a[i+x[k1]][j+y[k1]] - '0';
						}
				res = max(curr, res);
			}


		return res;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"11",
 "11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,1,1,-1,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,1,0,1,0,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(0, Arg3, place(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"11",
 "11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(1, Arg3, place(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"15",
 "61"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 11; verify_case(2, Arg3, place(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"151",
 "655",
 "661"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,1,0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 33; verify_case(3, Arg3, place(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"303",
 "333",
 "000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 12; verify_case(4, Arg3, place(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"0000000",
 "1010101"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {-1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(5, Arg3, place(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Coversta().run_test(0);
}
// END CUT HERE
