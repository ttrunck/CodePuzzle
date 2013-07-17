#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

typedef long long ent;

map<ent,int> m;

bool f(int i, int j){return i>j;}

ent sig(ent n){
  ent nn=n;
  int compt=0;
  while(nn!=0){
    compt++;
    nn/=10;
  }

  int t[compt];
  nn=n;
  for(int i=0;i<compt;++i){
    t[i]=nn%10;
    nn/=10;
  }
  
  sort(t,t+compt,f);
  int res=0;
  ent tmp=0;
  for(int i=0;i<compt;++i)
    tmp=tmp*10+t[i];
  return tmp;
}

bool ok(ent n){
  ent tmp=sig(n);
  if(m.count(tmp)>0)
    m[tmp]=m[tmp]+1;
  else
    m[tmp]=1;
  if(m[tmp]>=5) return true;
  return false;
}

int main(){
  ent tmp=0;
  while(!ok(tmp*tmp*tmp))++tmp;
  ent res=0;
  while(sig(res*res*res)!=sig(tmp*tmp*tmp)) ++res;
  cout << res*res*res << '\n';
}
