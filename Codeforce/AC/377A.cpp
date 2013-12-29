#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int, int> pi;
const vector<pi> dir{pi{1,0}, pi{-1,0}, pi{0,1}, pi{0,-1}};

struct triple{
  int x,y,d;
  triple(int a=0, int b=0, int c=0):x(a), y(b), d(c){};
  
  bool operator<(const triple& t) const{
    return d<t.d;
  }
};

int main(){
  int n,m,k;
  cin >> n >> m >> k;
  vector<string> t(n);
  for(int i=0;i<n;++i)
    cin >> t[i];

  vector<vector<int> > dist(n, vector<int>(m,-1));

  int x=0,y=0;
  for(int i=0;i<n;++i)
    for(int j=0;j<m;++j)
      if(t[i][j]=='.'){
	x=i;
	y=j;
      }

  queue<pi> q;
  q.push(pi{x,y});
  dist[x][y]=0;
  while(!q.empty()){
    x=q.front().first;
    y=q.front().second;
    q.pop();
    
    for(const pi& d:dir){
      int nx=x+d.first, ny=y+d.second;
      if(nx>=0 && nx<n && ny>=0 && ny<m && t[nx][ny]!='#' && dist[nx][ny]==-1){
	dist[nx][ny]=1+dist[x][y];
	q.push(pi{nx,ny});
      }
    }
  }

  priority_queue<triple> qt;
  for(int i=0;i<n;++i)
    for(int j=0;j<m;++j)
      if(t[i][j]!='#')
	qt.push(triple(i,j,dist[i][j]));

  for(int i=0;i<k;++i){
    triple tt=qt.top();
    qt.pop();
    t[tt.x][tt.y]='X';
  }

  for(int i=0;i<n;++i)
    cout << t[i] << '\n';

}
