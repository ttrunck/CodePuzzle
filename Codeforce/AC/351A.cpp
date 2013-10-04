#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<iomanip>

using namespace std;

const int MOD = 1000;

int main(){

  int n;
  cin >> n;
  n*=2;
  vector<int> t(n);

  for(int i=0;i<n;++i){
    double tmp;
    cin >> tmp;
    t[i] = int(tmp*MOD+0.5)%MOD;
  }
  
 for(int x:t)
    cerr << x << ' ';
  cerr << '\n';

  sort(begin(t), end(t));

  for(int x:t)
    cerr << x << ' ';
  cerr << '\n';

  int res=1000000000; 
  for(int start=0;start<n;++start){
    int tmp=0;
    int dep=start;
    int fin=(n+start-1)%n;
    
    cerr << "start :" << dep << ' ' << fin << ' ';

    for(int i=0;i<n;i+=2){
      tmp-=t[dep];
      tmp+=(MOD-t[fin])%MOD;
      dep = (dep+1)%n;
      fin = (fin+n-1)%n;
    }

    cerr << tmp << endl;

    res=min(res, abs(tmp));
  }


  cout <<  fixed << setprecision(3) << double(res)/MOD << '\n';
}
