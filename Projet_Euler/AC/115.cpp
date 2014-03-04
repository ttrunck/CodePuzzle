#include<iostream>

typedef long long ent;

using namespace std;

ent t[60][1000];

ent tilling(int m, int n){
  if(n==0) return 1;
  if(n<0) return 0;
  if(t[m][n]!=-1) return t[m][n];
  ent tmp=tilling(m,n-1);
  for(int i=m;i<=n;++i)
    tmp+=(n==i)?1:tilling(m,n-i-1);
  t[m][n]=tmp;
  return tmp;
}

int main(){
  for(int i=0;i<60;++i)
    for(int j=0;j<1000;++j)
      t[i][j]=-1;

    // for(int i=2;i<8;++i)
    //  cout << i << ' ' << tilling(i) << '\n';

  int res=0;
  while(tilling(50,res)<1000000) ++res;
  cout << res << '\n';
}
