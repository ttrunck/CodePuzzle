#include<iostream>
#include<vector>
#include<queue>
#include<limits>

using namespace std;

const int INF=numeric_limits<int>::max();

bool bfs(const vector<vector<int> >& g, const vector<vector<int> >& flow, const vector<vector<int> >& capa, vector<int>& pred){
  int n=g.size();
  pred.assign(n,-1);
  pred[0]=0;
  queue<int> q;
  q.push(0);
  while(!q.empty()){
    int v=q.front();
    q.pop();
    for(int i=0;i<int(g[v].size());++i)
      if(pred[g[v][i]]==-1 && flow[v][g[v][i]]< capa[v][g[v][i]]){
	pred[g[v][i]]=v;
	if(g[v][i]==n-1)
	  return true;
	q.push(g[v][i]);
      }
  }
  return false;
}

int edmond(const vector<vector<int> >& g, vector<vector<int> >& flow, vector<vector<int> >& capa){
  int res=0;
  vector<int> pred;
  while(bfs(g,flow,capa,pred)){
    ++res;
    int tmp=g.size()-1;
    while(tmp!=0){
      flow[pred[tmp]][tmp]+=1;
      flow[tmp][pred[tmp]]-=1;
      tmp=pred[tmp];
    }
  }
  return res;
}


int main(){
  ios::sync_with_stdio(false);
  int r,c,n;
  while(cin >> r >> c >> n && (r||c||n)){
    vector<vector<int> > g(2+r+c);
    vector<vector<int> > flow(2+r+c, vector<int>(2+r+c));
    vector<vector<int> > capa(2+r+c, vector<int>(2+r+c));

    for(int i=0;i<r;++i){
      g[0].push_back(1+i);
      capa[0][1+i]=1;
    }
    for(int i=0;i<c;++i){
      g[1+r+i].push_back(1+r+c);
      capa[1+r+i][1+r+c]=1;
    }

    for(int i=0;i<n;++i){
      int x,y;
      cin >> x >> y;
      --x;--y;
      g[1+x].push_back(1+r+y);
      g[1+r+y].push_back(1+x);
      capa[1+x][1+r+y]=1;

    }
    
    /*
    for(int i=0;i<int(g.size());++i){
      for(int j=0;j<int(g[i].size());++j)
	cerr << g[i][j] << ',' << capa[i][g[i][j]] << ' ';
      cerr << endl;
    }
    */
    int res=edmond(g,flow,capa);
    cout << res;

    vector<int> pred(2+r+c, -1);
    bfs(g,flow,capa,pred);
    for(int i=0;i<r;++i)
      if(pred[1+i]==-1)
	cout << " r"<< i+1;
    for(int i=0;i<c;++i)
      if(pred[1+r+i]!=-1)
	cout << " c"<< i+1;
    
    cout << endl;

  }
}
