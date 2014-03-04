#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int r, c;

void f(int x,int y, int d, vector<vector<int> > & dist, const vector<vector<bool> > & t, queue<pair<int, int> > & q){
  if(x>=0 && x<r && y>=0 && y<c && dist[x][y]==-1 && t[x][y]){
      dist[x][y]=d+1;
      q.push(make_pair(x,y));
    }
}

int main(){
  while(cin >> r >> c &&(r||c)){
    vector<vector<bool> > t(r,vector<bool>(c,true));
    int nb_bomb;
    cin >> nb_bomb;
    for(int i=0;i<nb_bomb;++i){
      int x,nb;
      cin >> x >> nb;
      for(int j=0;j<nb;++j){
	int y;
	cin >> y;
	t[x][y]=false;
      }
    }

    int xs,ys,xe,ye;
    cin >> xs >> ys >> xe >> ye;

    vector<vector<int> > dist(r,vector<int>(c,-1));
    queue<pair<int, int> > q;
    dist[xs][ys]=0;
    q.push(make_pair(xs,ys));
    int res=-1;
    while(!q.empty()){
      pair<int, int> curr=q.front();
      q.pop();
      int d=dist[curr.first][curr.second];
      if(curr.first==xe && curr.second==ye){
	res=d;
	break;
      }
      f(curr.first-1,curr.second,d,dist,t,q);
      f(curr.first+1,curr.second,d,dist,t,q);
      f(curr.first,curr.second-1,d,dist,t,q);
      f(curr.first,curr.second+1,d,dist,t,q);
    }
    cout << res << '\n';
  }
}
