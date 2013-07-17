#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int const N=20000;
vector<int> t[N];
int d[N];
int cas=1;

void bfs(int start, int ttl){
  d[start]=0;
  queue<int> q;
  q.push(start);
  while(!q.empty()){
    int curr=q.front();
    q.pop();
    if(d[curr]<ttl)
      for(int i=0;i<t[curr].size();++i){
	if(d[t[curr][i]]==-1){
	  d[t[curr][i]]= d[curr]+1;
	  q.push(t[curr][i]);
	}
      }   
  }
}

int main(){
  int n;
  cin >> n;
  while(n!=0){
    for(int i=0;i<N;++i){
      t[i].clear();
      d[i]=-2;
    }
    for(int i=0;i<n;++i){
      int a,b;
      cin >> a >> b;
      t[a].push_back(b);
      t[b].push_back(a);
      d[a]=-1;
      d[b]=-1;
    }
    int start, ttl;
    cin >> start >> ttl;
    while(start !=0 || ttl !=0){
      bfs(start, ttl);
      int res=0;
      for(int i=0;i<N;++i)
	if(d[i]==-1)
	  ++res;
	else if(d[i]!=-2)
	  d[i]=-1;
      cout << "Case " << cas << ": " << res << " nodes not reachable from node " << start << " with TTL = " << ttl << '.' << endl;
      cas++;
      cin >> start >> ttl;
    }
    cin >> n;
  }
}
