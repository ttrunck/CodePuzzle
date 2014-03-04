#include<iostream>
#include<vector>
#include<utility>
#include<limits>

using namespace std;

vector<pair<int, int> > t;
vector<vector<int> > mem;

int ks(int s, int n){
  //  cerr << s << ' ' << n << endl;
  if(s<0) return numeric_limits<int>::min();
  if(n==-1) return 0;
  if(mem[n][s]!=-1) return mem[n][s];
  int tmp=max(ks(s, n-1), ks(s-t[n].second, n-1)+t[n].first);
  mem[n][s]=tmp;
  return tmp;
}

int main(){
  int cas;
  cin >> cas;
  while(cas--){
    int n;
    cin >> n;
    t=vector<pair<int, int> >(n);
    mem=vector<vector<int> >(n, vector<int>(35,-1));
    for(int i=0;i<n;++i)
      cin >> t[i].first >> t[i].second;
    int f;
    cin >> f;
    int res=0;
    for(int i=0;i<f;++i){
      int tmp;
      cin >> tmp;
      res+=ks(tmp, n-1);
    }
    cout << res << endl;
  }
}
