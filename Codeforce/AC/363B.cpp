#include<iostream>
#include<vector>

using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> t(n);
  for(int i=0;i<n;++i)
    cin >> t[i];

  int maxi=0;
  int res=0;
  int curr=0;
  
  for(int i=0;i<k;++i)
    curr+=t[i];

  maxi=curr;

  for(int i=k;i<n;++i){
    curr+=t[i]-t[i-k];
    if(curr<maxi){
      res=i-k+1;
      maxi=curr;
    }
  }

  cout << res+1 << '\n';
}
