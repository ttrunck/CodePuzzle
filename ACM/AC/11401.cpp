#include<iostream>

typedef long long ent;

int const N=1000009;
ent m[N];

using namespace std;

ent aux(ent n){
  if(m[n]!=-1) return m[n];
  ent res=aux(n-1);
  ent b=n/2+1;
  res+=n*(n-1)-(n+1)*(n-b)-b*(b-1);
  m[n]=res;
  return res;
}

int main(){
  for(int i=4;i<N;++i)
    m[i]=-1;
  for(int i=0;i<4;++i)
    m[i]=0;
  for(int i=0;i<N;++i)
    aux(i);
  ent n;
  cin >> n;
  while(n>=3){
    cout << aux(n) << endl;
    cin >> n;
  }
}
