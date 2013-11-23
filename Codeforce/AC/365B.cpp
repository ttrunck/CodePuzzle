#include<iostream>
#include<vector>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> t(n);
  for(int i=0;i<n;++i)
    cin >> t[i];

  vector<int> ok(n,0);
  ok[0]=1;
  ok[1]=2;

  for(int i=2;i<n;++i){
    if(t[i]==t[i-1]+t[i-2])
      ok[i]=ok[i-1]+1;
    else
      ok[i]=2;
  }

  int res=0;
  for(int x:ok)
    res=max(res, x);

  cout << res << '\n';
}
