#include<iostream>
#include<queue>
#include<set>

using namespace std;

const int N=2002;
int t[N][N];

int main(){
  int p1,p2;
  while(cin >> p1 && p1){
    for(int i=0;i<N;++i)
      for(int j=0;j<N;++j)
	t[i][j]=-1;


    queue<pair<int, int> > q;
    for(int i=0;i<p1;++i){
      int x,y;
      cin >> x >> y;
      q.push(make_pair(x,y));
      t[x][y]=0;
    }
    set<pair<int, int> > s;
    cin >> p2;
    for(int i=0;i<p2;++i){
      int x,y;
      cin >> x >> y;
      s.insert(make_pair(x,y));
    }
    try{
    while(!q.empty()){
      int x=q.front().first;
      int y=q.front().second;
      if(s.find(q.front())!=s.end())
	throw t[x][y];
      q.pop();
      int i,j;
      i=x+1;j=y;
      if(i>=0 && j>=0 && i<N && j<N && t[i][j]==-1){
	t[i][j]=t[x][y]+1;
	q.push(make_pair(i,j));
      }
   i=x-1;j=y;
      if(i>=0 && j>=0 && i<N && j<N && t[i][j]==-1){
	t[i][j]=t[x][y]+1;
	q.push(make_pair(i,j));
      }
   i=x;j=y+1;
      if(i>=0 && j>=0 && i<N && j<N && t[i][j]==-1){
	t[i][j]=t[x][y]+1;
	q.push(make_pair(i,j));
      }
   i=x;j=y-1;
      if(i>=0 && j>=0 && i<N && j<N && t[i][j]==-1){
	t[i][j]=t[x][y]+1;
	q.push(make_pair(i,j));
      }
      
    }
    }
    catch(int n){
      cout << n << '\n';
    }

  }
}
