#include<iostream>

typedef long long ent;

using namespace std;

ent m[100];

ent tilling(int n){
  if(n==0) return 1;
  if(n<0) return 0;
  if(m[n]!=-1) return m[n];
  ent tmp=tilling(n-2)+tilling(n-1)+tilling(n-3)+tilling(n-4);
  m[n]=tmp;
  return tmp;
}

int main(){
    for(int j=0;j<100;++j)
      m[j]=-1;

  cout << tilling(50) << '\n';
}
