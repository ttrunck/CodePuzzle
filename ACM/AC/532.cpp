#include<iostream>
#include<vector>
#include<queue>

using namespace std;


enum bloc {FREE, WALL, ENTER, EXIT};

int l,r,c;

struct point{
  int x,y,z;
  point(){}
  point(int xx, int yy, int zz):x(xx),y(yy),z(zz){}
};


inline void f(int x, int y, int z, int d, vector<vector<vector<int> > > & dist, queue<point> & q, const vector<vector<vector<bloc> > > & t){
  if(x>=0 && x<l && y>=0 && y<r && z>=0 && z<c && dist[x][y][z]==-1 && t[x][y][z]!=WALL){
      dist[x][y][z]=d+1;
      q.push(point(x,y,z));
    }
}

int aux(const vector<vector<vector<bloc> > > & t){
  point start;
  for(int i=0;i<l;++i)
    for(int j=0;j<r;++j)
      for(int k=0;k<c;++k)
	if(t[i][j][k]==ENTER){
	  start=point(i,j,k);
	  break;
	}
  vector<vector<vector<int> > > dist(l,vector<vector<int> >(r, vector<int>(c,-1)));
  queue<point> q;
  q.push(start);
  dist[start.x][start.y][start.z]=0;
  while(!q.empty()){
    point curr=q.front();
    q.pop();
    if(t[curr.x][curr.y][curr.z]==EXIT) return dist[curr.x][curr.y][curr.z];
    int d=dist[curr.x][curr.y][curr.z];   
    f(curr.x-1,curr.y,curr.z,d,dist,q,t);
    f(curr.x+1,curr.y,curr.z,d,dist,q,t);
    f(curr.x,curr.y-1,curr.z,d,dist,q,t);
    f(curr.x,curr.y+1,curr.z,d,dist,q,t);
    f(curr.x,curr.y,curr.z-1,d,dist,q,t);
    f(curr.x,curr.y,curr.z+1,d,dist,q,t);
  }
  return -1;
}

int main(){
  while(cin >> l >> r >> c && (l||r||c)){
    vector<vector<vector<bloc> > > t(l,vector<vector<bloc> >(r, vector<bloc>(c)));
    for(int i=0;i<l;++i)
      for(int j=0;j<r;++j)
	for(int k=0;k<c;++k){
	  char tmp;
	  cin >> tmp;
	  switch(tmp){
	  case 'S':
	    t[i][j][k]=ENTER;
	    break;
	  case 'E':
	    t[i][j][k]=EXIT;
	    break;
	  case '.':
	    t[i][j][k]=FREE;
	    break;
	  case '#':
	    t[i][j][k]=WALL;
	    break;
	  }
	}
    int tmp=aux(t);
    if(tmp==-1)
      cout << "Trapped!\n";
    else
      cout << "Escaped in " << tmp << " minute(s).\n";
  }
}
