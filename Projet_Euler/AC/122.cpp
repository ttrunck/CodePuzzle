#include<iostream>
#include<cmath>
#include<queue>
#include<vector>

using namespace std;

int const N=1000;

int r[N];
int p[N];
queue<int> q;

void aux(int i){
  vector<int> t;
  int pred=i;
  do{
    //cout << pred << ' ' << p[pred] << '\n';
    if(r[pred+i]!=-1 || pred+i>200){
      pred=p[pred];
      continue;
    }
    r[i+pred]=r[i]+1;
    p[i+pred]=i;
    t.push_back(i+pred);
    pred=p[pred];
  }while(p[pred]!=pred);
  //  cout << i << ':';
  for(int j=t.size()-1;j>=0;--j){
    //  cout << ' ' << t[j];
   q.push(t[j]);
  }
  //cout << '\n';
}

int main(){
  for(int i=0;i<N;++i){
    r[i]=-1;
    p[i]=-1;
  }

  r[1]=0;
  p[0]=0;
  p[1]=0; 
  q.push(1); 
  
  while(!q.empty()){
    int curr=q.front();
    aux(curr);
    q.pop();
  }

  int res=0;
  for(int i=1;i<=200;++i){
    if(r[i]==-1) cout << "PROBLEME\n";
    cout << i << ' ' << r[i] << '\n';
    res+=r[i];
  }
  cout << res-2 << '\n';
}
