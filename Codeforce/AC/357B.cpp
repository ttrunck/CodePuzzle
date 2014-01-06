#include<iostream>
#include<vector>

using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> t(n,0);

  for(int i=0;i<m;++i){
    int a,b,c;
    cin >> a >> b >> c;
    --a;--b;--c;
    if(t[b]!=0)
      swap(a,b);
    if(t[c]!=0)
      swap(a,c);
    if(t[a]==0)
      t[a]=1;
    t[b]=t[a]%3+1;
    t[c]=(t[a]+1)%3+1;
  }

  for(int x:t)
    cout << x << ' ';
}
