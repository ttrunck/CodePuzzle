#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdio>

typedef long long ent;
using namespace std;

int main(){
  int n, m;
  scanf("%d %d",&n, &m);
  vector<int> deg(n,0);
  ent res=n;
  res*=n-1;
  res*=n-2;
  res/=6;
  for(int i=0;i<m;++i){
    int a,b;
    scanf("%d %d",&a,&b);
    a--;
    b--;
    res+=-(n-2)+deg[a]+deg[b];
    deg[a]++;
    deg[b]++;
  }
  cout << res << '\n';
}
