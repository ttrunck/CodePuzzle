#include<sstream>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

const int MOD=1000000009;

typedef long long ll;

int choose(int k, int n){
  ll res=1;
  for(int i=n;i>n-k;--i)
    res=(res*i)%MOD;
  return res;
}

int fact(int n){
  ll res=1;
  for(int i=1;i<=n;++i)
    res=(res*i)%MOD;
  return res;
}

int aux(int s, int r, vector<vector<int> >& mem){
  if(r==0) return 1;
  if(s==26) return 0;
  if(mem[s][r]!=-1) return mem[s][r];
  ll res=0;

  for(int i=0;i<=r;++i)
    res = (res+aux(s+1, r-i, mem))%MOD; 

  return mem[s][r]=res;
}

 class StringWeightDiv2
        { 
        public: 
        int countMinimums(int L) 
            { 
	      if(L<=26) return choose(L,26);
	      vector<vector<int> > mem(26, vector<int>(1000,-1));
	      return (ll(fact(26))* ll(aux(0,L-26, mem)))%MOD;
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 26; verify_case(0, Arg1, countMinimums(Arg0)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 650; verify_case(1, Arg1, countMinimums(Arg0)); }
	void test_case_2() { int Arg0 = 50; int Arg1 = 488801539; verify_case(2, Arg1, countMinimums(Arg0)); }

// END CUT HERE
 
        }; 

    // BEGIN CUT HERE 
    int main()
        {
        StringWeightDiv2 ___test; 
        ___test.run_test(-1); 
        } 
    // END CUT HERE 
