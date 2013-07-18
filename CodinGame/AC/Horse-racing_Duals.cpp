#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> t(n);
  for(int i=0;i<n;++i)
    cin >> t[i];
  sort(begin(t),end(t));
  int res=t[1]-t[0];

  for(int i=1;i<n-1;++i)
    res=min(res,t[i+1]-t[i]);

  cout << res;
}
