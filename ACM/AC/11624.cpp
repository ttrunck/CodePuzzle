#include<iostream>
#include<vector>
#include<queue>
#include<limits>

using namespace std;

int r,c;

const int MAX=numeric_limits<int>::max();

void print(const vector<vector<int> > & t){
  for(int i=0;i<r;++i){
    for(int j=0;j<c;++j)
      cerr << t[i][j] << "  ";
    cerr << endl;
  }
  cerr << endl;
}

void fire(vector<vector<int> > & t){
  vector<vector<bool> > vu(r,vector<bool>(c,false));
  queue<pair<int, int> > q;
  for(int i=0;i<r;++i)
    for(int j=0;j<c;++j)
      if(t[i][j]==0)
	q.push(make_pair(i,j));

  while(!q.empty()){
    int x=q.front().first;
    int y=q.front().second;
    q.pop();
    if(vu[x][y]) continue;
    vu[x][y]=true;

    int i,j;

    i=x+1;j=y;
    if(i>=0 && j>=0 && i<r && j<c && !vu[i][j] && t[i][j]!=-1){
      t[i][j]=t[x][y]+1;
      q.push(make_pair(i,j));
    }
 i=x-1;j=y;
    if(i>=0 && j>=0 && i<r && j<c && !vu[i][j] && t[i][j]!=-1){
      t[i][j]=t[x][y]+1;
      q.push(make_pair(i,j));
    }
 i=x;j=y+1;
    if(i>=0 && j>=0 && i<r && j<c && !vu[i][j] && t[i][j]!=-1){
      t[i][j]=t[x][y]+1;
      q.push(make_pair(i,j));
    }
 i=x;j=y-1;
    if(i>=0 && j>=0 && i<r && j<c && !vu[i][j] && t[i][j]!=-1){
      t[i][j]=t[x][y]+1;
      q.push(make_pair(i,j));
    }
  }
}

int escape(int xs,int ys, const vector<vector<int> > & t){
  vector<vector<int> > vu(r,vector<int>(c,-1));
  queue<pair<int, int> > q;
  q.push(make_pair(xs,ys));
  vu[xs][ys]=0;

  while(!q.empty()){
    int x=q.front().first;
    int y=q.front().second;
    if(x==0 || y==0 || x==r-1 || y==c-1) return vu[x][y]+1;
    q.pop();
    
    int i,j;
    
    i=x+1;j=y;
    if(i>=0 && j>=0 && i<r && j<c && vu[i][j]==-1 && t[i][j]!=-1 && vu[x][y]+1<t[i][j]){
      vu[i][j]=vu[x][y]+1;
      q.push(make_pair(i,j));
    }
  i=x-1;j=y;
    if(i>=0 && j>=0 && i<r && j<c && vu[i][j]==-1 && t[i][j]!=-1 && vu[x][y]+1<t[i][j]){
      vu[i][j]=vu[x][y]+1;
      q.push(make_pair(i,j));
    }
  i=x;j=y+1;
    if(i>=0 && j>=0 && i<r && j<c && vu[i][j]==-1 && t[i][j]!=-1 && vu[x][y]+1<t[i][j]){
      vu[i][j]=vu[x][y]+1;
      q.push(make_pair(i,j));
    }
  i=x;j=y-1;
    if(i>=0 && j>=0 && i<r && j<c && vu[i][j]==-1 && t[i][j]!=-1 && vu[x][y]+1<t[i][j]){
      vu[i][j]=vu[x][y]+1;
      q.push(make_pair(i,j));
    }
  }
  return -1;
}

int main(){
  int cas;
  cin >> cas;
  while(cas--){
    cin >> r >> c;
    int xs,ys;
    vector<vector<int> > t(r,vector<int>(c,-1));
    for(int i=0;i<r;++i)
      for(int j=0;j<c;++j){
	char tmp;
	cin >> tmp;
	switch(tmp){
	case '.':
	  t[i][j]=MAX;
	  break;
	case 'J':
	  xs=i;ys=j;
	  t[i][j]=MAX;
	  break;
	case 'F':
	  t[i][j]=0;
	}
      }
    fire(t);
    int res=escape(xs,ys,t);
    if(res<0) cout << "IMPOSSIBLE\n";
    else cout << res << '\n';

  }
}
