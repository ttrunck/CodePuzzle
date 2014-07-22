#include<sstream>
#include<string>
#include<vector>
#include<iostream>
#include <set>
#include <queue>
using namespace std;

typedef pair<int, int> pi;

void aux(const pi& p, set<pi>& s){
	queue<pi> q;
	s.insert(p);
	q.push(p);
	while(!q.empty()){
		pi p =q.front();
		q.pop();
		pi p1{p.first, p.second-p.first};
		if(p1.first>0 && p1.second>0 && s.find(p1)==end(s)){
			s.insert(p1);
			q.push(p1);
		}

		pi p2{p.first-p.second, p.second};
		if(p2.first>0 && p2.second>0 && s.find(p2)==end(s)){
			s.insert(p2);
			q.push(p2);
		}
	}
}


 class PairGame
        { 
        public: 
        int maxSum(int a, int b, int c, int d) 
            { 
            	set<pi> poss1, poss2;
            	aux(pi{a, b}, poss1);
            	aux(pi{c, d}, poss2);

            	int res = -1;
            	for(const pi& p:poss1)
            		if(p.first+p.second>res && poss2.find(p)!=end(poss2))
            			res = p.first+p.second;
            	return res;
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 2; int Arg3 = 1; int Arg4 = 2; verify_case(0, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 15; int Arg1 = 4; int Arg2 = 10; int Arg3 = 7; int Arg4 = 7; verify_case(1, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 10; int Arg3 = 10; int Arg4 = -1; verify_case(2, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 1000; int Arg1 = 1001; int Arg2 = 2000; int Arg3 = 2001; int Arg4 = 1001; verify_case(3, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 10944; int Arg1 = 17928; int Arg2 = 7704; int Arg3 = 21888; int Arg4 = 144; verify_case(4, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 1; int Arg1 = 1000000; int Arg2 = 1; int Arg3 = 6; int Arg4 = 7; verify_case(5, Arg4, maxSum(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
        }; 

    // BEGIN CUT HERE 
    int main()
        {
        PairGame ___test; 
        ___test.run_test(-1); 
        } 
    // END CUT HERE 
