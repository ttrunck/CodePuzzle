#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

const int maxi=1000000000;

int const nb_point=82;
int tab[nb_point][nb_point];
int dist[nb_point][nb_point];
bool visited[nb_point][nb_point];

struct vert{
  int numx;
  int numy;
  int dist;
  vert(int nx, int ny, int d): numx(nx), numy(ny), dist(d) {};
};

struct comp{
  bool operator()(vert & v1, vert &v2){
    return (v1.dist>v2.dist);
  };
};

void relacher(int ux, int uy, int vx, int vy, double w){
  double d2= dist[ux][uy]+w;
  if ((dist[vx][vy]<0)||(dist[vx][vy]>d2)){
    dist[vx][vy]=d2;
  }
}

int dijkstra(int startx, int starty, int destx){
  priority_queue<vert, vector<vert>, comp> q;
  int ux, uy;
  for(int i=0;i<nb_point;++i)
    for(int j=0;j<nb_point;++j){
      dist[i][j]=-1;
      visited[i][j]=false;
    }
  
  dist[startx][starty]=tab[startx][starty];
  q.push(vert(startx,starty,0));
  while(!q.empty()){
    ux=q.top().numx;
    uy=q.top().numy;
    if (uy==destx) return q.top().dist;
    q.pop();
    if(!visited[ux][uy]){
      int vx, vy;
     
      vx=ux;
      vy=uy+1;
      relacher(ux, uy, vx, vy, tab[vx][vy]);
      if(!visited[vx][vy]) q.push(vert(vx, vy, dist[vx][vy]));

      vx=ux-1;
      vy=uy;
      relacher(ux, uy, vx, vy, tab[vx][vy]);
      if(!visited[vx][vy]) q.push(vert(vx, vy, dist[vx][vy]));

      vx=ux+1;
      vy=uy;
      relacher(ux, uy, vx, vy, tab[vx][vy]);
      if(!visited[vx][vy]) q.push(vert(vx, vy, dist[vx][vy]));

    }
    visited[ux][uy]=true;
  }
  return -1;
}


int main(){
  for(int i=0;i<nb_point;++i){
    tab[0][i]=maxi;
    tab[nb_point-1][i]=maxi;
    tab[i][0]=maxi;
    tab[i][nb_point-1]=maxi;
  }
  for(int i=1;i<nb_point-1;++i)
    for(int j=1;j<nb_point-1;++j)
      cin >> tab[i][j];

  int mini=maxi;
  for(int i=1;i<nb_point-1;++i){
    //  cout << i << ' ' << dijkstra(i,1,nb_point-2) << '\n';
    mini=min(dijkstra(i,1,nb_point-2),mini);
  }
  cout << mini << '\n';
}
