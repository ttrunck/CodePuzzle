#include<iostream>
#include<vector>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> t(n);
  for(int i=0;i<n;++i)
    cin >> t[i];

  int res=0;
  int maxi=t[0];
  for(int i=1;i<n;++i){
    res=min(res, t[i]-maxi);
    maxi=max(maxi, t[i]);
  }


  cout << res;
}
