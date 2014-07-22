#include<sstream>
#include<string>
#include<vector>
#include<iostream>
#include <queue>
using namespace std;

typedef long long ll;

ll bfs(int x, const vector<vector<int>>& g, const int N){
    int n = g.size();
    vector<ll> dist(n, -1);
    queue<int> q;
    dist[x] = 0;
    q.push(x);
    ll res = 0; 
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int u:g[v])
            if(dist[u]==-1){
                dist[u] = dist[v]+1;
                if(u>x && u<N) res+= dist[u];
                q.push(u);
            }
    }
    return res;
}

 class CliqueGraph
        { 
        public: 
        long long calcSum(int N, vector <int> V, vector <int> sizes) 
            { 
                int m = sizes.size();
                vector<vector<int>> g(N+m);
                int curr = 0;
                for(int i=0;i<int(sizes.size());++i){
                    int next = curr + sizes[i];
                    for(int j=curr;j<min(int(V.size()), next);++j){
                            g[V[j]].push_back(N+i);
                            g[N+i].push_back(V[j]);
                        }
                    curr = next;    
                }
                ll res = 0;
                for(int i=0;i<N;++i)
                    res += bfs(i, g, N);
                return res/2;
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = {0,1,2,0,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 8LL; verify_case(0, Arg3, calcSum(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {0,1,2,3,1,2,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 12LL; verify_case(1, Arg3, calcSum(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 15; int Arr1[] = {1,3,5,7,9,11,13,0
,2,3,6,7,10,11,14,0
,4,5,6,7,12,13,14,0
,8,9,10,11,12,13,14,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {8,8,8,8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 130LL; verify_case(2, Arg3, calcSum(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
        }; 

    // BEGIN CUT HERE 
    int main()
        {
        CliqueGraph ___test; 
        ___test.run_test(-1); 
        } 
    // END CUT HERE 
