#include<iostream>
#include<vector>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> t(n);
  for(int i=0;i<n;++i)
    cin >> t[i];
  int x,y;
  cin >> x >> y;

  int noob=0;
  int good=0;
  for(int x:t)
    good+=x;

  int res=0;
  while(res<n && (good>y || good<x || noob<x || noob>y)){
    good-=t[res];
    noob+=t[res];
    ++res;
  }
  if(res==n)
    res=-1;

  cout << res+1 << '\n';
}
