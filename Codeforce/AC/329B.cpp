#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int,int> pi;

const int INF = 10000000;

int main(){
  vector<pi> d;
  d.push_back(pi(1,0));
  d.push_back(pi(-1,0));
  d.push_back(pi(0,1));
  d.push_back(pi(0,-1));

  int n,m;
  cin >> n >> m;
  vector<vector<char> > t(n, vector<char>(m));
  vector<vector<int> > dist(n, vector<int>(m,INF));
  pi s,e;
  for(int i=0;i<n;++i)
    for(int j=0;j<m;++j){
      cin >> t[i][j];
      if(t[i][j]=='S')
	s=pi(i,j);
      if(t[i][j]=='E')
	e=pi(i,j);
    }

  queue<pi> q;
  dist[e.first][e.second] = 0;
  q.push(e);
  while(!q.empty()){
    pi curr= q.front();
    q.pop();
    for(int i=0;i<4;++i)
      if(curr.first+d[i].first>=0
	 && curr.first+d[i].first<n
	 && curr.second+d[i].second>=0
	 && curr.second+d[i].second<m
	 && t[curr.first+d[i].first][curr.second+d[i].second]!='T'
	 && dist[curr.first+d[i].first][curr.second+d[i].second]==INF){
	q.push(pi(curr.first+d[i].first, curr.second+d[i].second));
	dist[curr.first+d[i].first][curr.second+d[i].second] = 1+dist[curr.first][curr.second];
      }
  }

  /*
  for(int i=0;i<n;++i){
    for(int j=0;j<m;++j)
      cerr << dist[i][j] << ' ';
    cerr << endl;
  }

 for(int i=0;i<n;++i){
    for(int j=0;j<m;++j)
      cerr << t[i][j] << ' ';
    cerr << endl;
  }
  */

  int res=0;
  int dd=dist[s.first][s.second];
   for(int i=0;i<n;++i)
    for(int j=0;j<m;++j)
      if(isdigit(t[i][j]) && dist[i][j]<=dd)
	res+=(t[i][j]-'0');
  
  cout << res << '\n';
}
