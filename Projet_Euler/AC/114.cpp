#include<iostream>

typedef long long ent;

using namespace std;

ent m[100];

ent tilling(int n){
  if(n==0) return 1;
  if(n<0) return 0;
  if(m[n]!=-1) return m[n];
  ent tmp=tilling(n-1);
  for(int i=3;i<=n;++i)
    tmp+=(n==i)?1:tilling(n-i-1);
  m[n]=tmp;
  return tmp;
}

int main(){
    for(int j=0;j<100;++j)
      m[j]=-1;

    // for(int i=2;i<8;++i)
    //  cout << i << ' ' << tilling(i) << '\n';

    cout << tilling(50) << '\n';
}
