#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void bfs(int s, const vector<vector<int> >& t, vector<int>& dist){
  queue<int> q;
  q.push(s);
  dist[s]=0;
  while(!q.empty()){
    int v = q.front();
    q.pop();
    for(int u:t[v])
      if(dist[u]==-1){
	dist[u]=1+dist[v];
	q.push(u);
      }
  }
}

//compute the diameter of the given tree
int diam(int node, const vector<vector<int> >& t){
  vector<int> dist(t.size(), -1);
  bfs(node, t, dist);
  int v, dist_max=-1;
  for(int i=0;i<int(t.size());++i)
    if(dist[i]>dist_max){
      v=i;
      dist_max=dist[i];
    }
  dist.assign(t.size(), -1);
  bfs(v, t, dist);

  dist_max=0;
  for(int d:dist)
    dist_max=max(dist_max, d);

  return dist_max;
}

int main(){
  int N;
  cin >> N;
  int node;
  vector<vector<int> > t(200000);
  for(int i=0;i<N;++i){
    int a,b;
    cin >> a >> b;
    t[a].push_back(b);
    t[b].push_back(a);
    node=a;
  }

  int d=diam(node, t);
  cout << (d+1)/2 << '\n';
  
}
