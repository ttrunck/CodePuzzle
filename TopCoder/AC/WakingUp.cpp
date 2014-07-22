#include<sstream>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

const int INF = 1000000000;

int gcd(int a, int b)
{
    while (b != 0) {
        int c = b;
        b = a % b;
        a = c;
    }
    return a;
}

class WakingUp
{ 
public: 
    int maxSleepiness(vector <int> period, vector <int> start, vector <int> volume, int D) 
    { 
       int N = 1;
       for (int x: period) {
           N = N * (x / gcd(N,x));
       } 
       vector<int> v(N+1, 0);
       int n = period.size();
       for(int i=0;i<n;++i)
        for(int j=start[i];j<=N;j+=period[i])
            v[j]+= volume[i];

        int res = 0;
        int curr = 0;
        for(int i=1;i<=N;++i){
            curr += D;
            curr -= v[i];
            res = min(res, curr);
        }
        if(curr < 0)
            return -1;
        return -res;               
    }


}; 



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
