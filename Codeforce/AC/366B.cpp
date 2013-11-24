#include<iostream>
#include<vector>

using namespace std;

const int INF=1000000000;

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> t(n);
  for(int i=0;i<n;++i)
    cin >> t[i];

  int res, mini=INF;
  for(int i=0;i<k;++i){
    int tmp=0;
    for(int j=i;j<n;j+=k)
      tmp+=t[j];
    if(tmp<mini){
      res=i;
      mini=tmp;
    }
  }

  cout << res+1 << '\n';

}
