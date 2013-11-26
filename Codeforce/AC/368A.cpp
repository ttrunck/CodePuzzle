#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
  int n,d;
  cin >> n >> d;
  vector<int> t(n);
  for(int i=0;i<n;++i)
    cin >> t[i];
  
  sort(begin(t), end(t));
  
  int m;
  cin >> m;
  
  int res=0;
  for(int i=0;i<min(n,m);++i)
    res+=t[i];
 
  if(n<m)
    res-=(m-n)*d;


  cout << res << '\n';
}
