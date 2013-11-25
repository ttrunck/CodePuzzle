#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> t(m);
  for(int i=0;i<m;++i)
    cin >> t[i];
  sort(begin(t), end(t));

  bool res=true;
  if(m>0 && (t[0]==1 || t.back()==n))
    res=false;
  for(int i=2;i<m && res;++i)
    if(t[i-2]+1==t[i-1] && t[i-1]+1==t[i])
      res=false;

  if(res)
    cout << "YES\n";
  else
    cout << "NO\n";
}
