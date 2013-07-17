#include<iostream>

using namespace std;

typedef long long ent;

int const S=200;
ent t[S][10];

ent aux(int taille, int dep){
  if(taille==0) return 1;
  ent res=0;
  if(t[taille][dep]!=-1) return t[taille][dep];
  for(int i=dep;i<10;++i)
    res+=aux(taille-1,i);
  t[taille][dep]=res;
  return res;
}

ent bouncy(int t){
  ent res=0;
  res+=aux(t,0);
  for(int i=2;i<=t;++i)
    res+=aux(i,0);
  res-=(t-1)*10;
  return res;
}

int main(){
  for(int i=0;i<S;++i)
    for(int j=0;j<10;++j)
      t[i][j]=-1;

  cout << bouncy(100)-1 << '\n';
}
