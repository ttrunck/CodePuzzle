#include<iostream>

typedef long long ent;

using namespace std;

ent m[5][100];

ent tilling(int t, int n){
  if(m[t][n]!=-1) return m[t][n];
  if(n-t<0) return 1;
  ent tmp=tilling(t, n-t)+tilling(t, n-1);
  m[t][n]=tmp;
  return tmp;
}

int main(){
  for(int i=0;i<5;++i)
    for(int j=0;j<100;++j)
      m[i][j]=-1;

  ent res=0;
  res+=tilling(2,50)-1;
  res+=tilling(3,50)-1;
  res+=tilling(4,50)-1;
  cout << res << '\n';
}
