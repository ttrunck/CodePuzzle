#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>

using namespace std;

typedef pair<int, int> pi;

int main(){
  int n,M;
  cin >> n >> M;
  vector<string> t(n);
  for(int i=0;i<n;++i)
    cin >> t[i];

  vector<vector<int> > m(n, vector<int>(M,-1));
  
  for(int i=0;i<n;++i){
    queue<pi> q;
    for(int j=0;j<M;++j)
      if(t[i][j]=='1'){
	q.push(pi(j,0));
	m[i][j]=0;
      }
    while(!q.empty()){
      pi curr=q.front();
      q.pop();
      if(m[i][(curr.first-1+M)%M]==-1){
	q.push(pi((curr.first-1+M)%M, curr.second+1));
	m[i][(curr.first-1+M)%M]=curr.second+1;
      }
      if(m[i][(curr.first+1)%M]==-1){
	q.push(pi((curr.first+1)%M, curr.second+1));
	m[i][(curr.first+1)%M]=curr.second+1;
      }
    }
  }
  
  vector<int> res(M,0);
  for(int j=0;j<M;++j){
    for(int i=0;i<n;++i)
      if(m[i][j]==-1){
	res[j]=-1;
	break;
      }
      else
	res[j]+=m[i][j];
  }

  int sol=res[0];
  for(int i=0;i<M;++i)
    sol=min(sol, res[i]);

  cout << sol << '\n';
}
