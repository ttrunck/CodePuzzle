#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
  int n,m,i,j,a,b;
  cin >> n >> m >> i >> j >> a >> b;

  if((i==1 || i==n) && (j==1 || j==m)){
    cout << "0\n";
    return 0;
  }

  if((i+a>n && i-a<1) || (j+b>m && j-b<1)){
    cout << "Poor Inna and pony!\n";
    return 0;
}

  vector<int> dista(n+1, -1);
  dista[i]=0;
  queue<int> qa;
  qa.push(i);
  while(!qa.empty()){
    int curr=qa.front();
    qa.pop();
    if(curr-a>0 && dista[curr-a]==-1){
      dista[curr-a]=dista[curr]+1;
      qa.push(curr-a);
    }
    if(curr+a<=n && dista[curr+a]==-1){
      dista[curr+a]=dista[curr]+1;
      qa.push(curr+a);
    }
  }

  vector<int> distb(m+1, -1);
  distb[j]=0;
  queue<int> qb;
  qb.push(j);
  while(!qb.empty()){
    int curr=qb.front();
    qb.pop();
    if(curr-b>0 && distb[curr-b]==-1){
      distb[curr-b]=distb[curr]+1;
      qb.push(curr-b);
    }
    if(curr+b<=m && distb[curr+b]==-1){
      distb[curr+b]=distb[curr]+1;
      qb.push(curr+b);
    }
  }

  

  int res=2*(n+m);

  cerr << dista[1] << ' ' << dista[n] << ' ' << distb[1] << ' ' << distb[m] << endl;

  if(dista[1]!=-1 && distb[1]!=-1 && (dista[1]-distb[1])%2==0)
    res=min(res, max(dista[1], distb[1]));
  
  if(dista[1]!=-1 && distb[m]!=-1 && (dista[1]-distb[m])%2==0)
    res=min(res, max(dista[1], distb[m]));

  if(dista[n]!=-1 && distb[1]!=-1 && (dista[n]-distb[1])%2==0)
    res=min(res, max(dista[n], distb[1]));
  
  if(dista[n]!=-1 && distb[m]!=-1 && (dista[n]-distb[m])%2==0)
    res=min(res, max(dista[n], distb[m]));

  if(res==2*(n+m))
    cout << "Poor Inna and pony!\n";
  else
    cout << res << '\n';
}
