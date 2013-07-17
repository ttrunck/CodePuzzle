#include<sstream>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

bool inter(int N, int s, int e, int bits){
  bool se=false, es=false;
  for(int i=0;i<N;++i)
    if(((bits>>i)&1)==1){
      if(i>s && i<e)
	se=true;
      else if(i!=s && i!=e)
	es=true;
    }
    return se && es;
}

long long aux(int N, int last, int bits, vector<vector<long long> > & mem){
  if(bits==(1<<N)-1){
    if(inter(N, 0, last, bits))
      return 1;
    else
      return 0;
  }

  if(mem[bits][last]!=-1) return mem[bits][last];
  
  long long res=0;

  for(int i=0;i<N;++i)
    if(((bits>>i)&1)!=1 && inter(N, min(last, i), max(i, last), bits))
      res+=aux(N, i, bits|(1<<i), mem);
  
  return mem[bits][last]=res;
}

 class PolygonTraversal
        { 
        public: 
        long long count(int N, vector <int> points) 
            { 
	      for(int i=1;i<int(points.size());++i)
		points[i]=(points[i]-points[0]+N)%N;
	      points[0]=0;
	      int bits=0;
	      int last = points.back();
	      for(int i=0;i<int(points.size());++i)
		bits= bits|(1<<points[i]);
	      vector<vector<long long> > mem(1<<N, vector<long long>(N,-1));
	      return aux(N, last, bits, mem);
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arr1[] = {1, 3, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1LL; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 6; int Arr1[] = {1, 4, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1LL; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 7; int Arr1[] = {2, 4, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 2LL; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 7; int Arr1[] = {1, 2, 3, 4, 6, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 18; int Arr1[] = {1, 7, 18}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 4374612736LL; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE
 
        }; 

    // BEGIN CUT HERE 
    int main()
        {
        PolygonTraversal ___test; 
        ___test.run_test(-1); 
        } 
    // END CUT HERE 
