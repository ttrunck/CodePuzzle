#include<sstream>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

bool col(int x, int c, const vector<vector<int>>& g, vector<int>& color){
    for(int v:g[x]){
        if(color[v]==c) return false;
        if(color[v]==-1){
            color[v] = 1-c;
            if(!col(v, 1-c, g, color))
                return false;
        }
    }
    return true;
}

 class Family
        { 
        public: 
        string isFamily(vector <int> parent1, vector <int> parent2) 
            { 
                int n=parent1.size();
                vector<vector<int>> g(n);
                for(int i=0;i<n;++i){
                    if(parent1[i]!=-1){
                        g[parent1[i]].push_back(parent2[i]);
                        g[parent2[i]].push_back(parent1[i]);
                    }
                }
                vector<int> color(n, -1);
                for(int i=0;i<n;++i)
                    if(color[i]==-1){
                        color[i]=0;
                        if(!col(i, 0, g, color))   
                            return "Impossible";
                    }
                return "Possible";                     
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-1,-1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(0, Arg2, isFamily(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {-1,-1,-1,-1,-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,-1,-1,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(1, Arg2, isFamily(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-1,-1,0,0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,1,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Impossible"; verify_case(2, Arg2, isFamily(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {-1,-1,-1,-1,1,-1,0,5,6,-1,0,3,8,6}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,-1,-1,3,-1,4,6,5,-1,5,4,6,1}
; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(3, Arg2, isFamily(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {-1,-1,-1,2,2,-1,5,6,4,6,2,1,8,0,2,4,6,9,-1,16,-1,11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,-1,1,0,-1,1,4,2,0,4,8,2,3,0,5,14,14,-1,7,-1,13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Impossible"; verify_case(4, Arg2, isFamily(Arg0, Arg1)); }

// END CUT HERE
 
        }; 

    // BEGIN CUT HERE 
    int main()
        {
        Family ___test; 
        ___test.run_test(-1); 
        } 
    // END CUT HERE 
