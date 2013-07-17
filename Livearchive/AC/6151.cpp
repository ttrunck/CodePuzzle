#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

int bfs(int start, const vector<vector<int> > & t){
  int n=t.size();
  int res=n+1;
  vector<int> visit(n,-1);
  queue<int> q;
  q.push(start);
  visit[start]=0;
  while(!q.empty()){
    int curr=q.front();
    q.pop();
    if(2*visit[curr]+1>res) return res;
    for(int i=0;i<int(t[curr].size());++i)
      if(visit[t[curr][i]]==-1){
	q.push(t[curr][i]);
	visit[t[curr][i]]=visit[curr]+1;
      }
      else if(visit[t[curr][i]]>=visit[curr])
	res=min(res, visit[curr]+visit[t[curr][i]]+1);
  }
  /*
  for(int i=0;i<n;++i)
    cerr << visit[i] << ' ';
      cerr << endl;
  */  
return res;
}

int main(){
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for(int icase=1;icase<=T;++icase){
    cout << "Case " << icase << ": ";
    int n, m;
    cin >> n >> m;
    vector<vector<int> > t(n);
    for(int i=0;i<m;++i){
      int a,b;
      cin >> a >> b;
      t[a].push_back(b);
      t[b].push_back(a);
    }
    
    int res=n+1;

    for(int i=0;i<n;++i)
      res=min(res, bfs(i, t));

    if(res==n+1)
      cout << "impossible\n";
    else
      cout << res << '\n';
  }
}
