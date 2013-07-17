#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

typedef pair<int,int> pi;

int s,a,m,n;

int in(int x, int y){
  return 1+2*(x*a+y);
}

int out(int x, int y){
  return 2+2*(x*a+y);
}

bool bfs(const vector<vector<int> >& g, const vector<vector<int> >& flow, vector<int>& pred){
  pred.assign(n,-1);
  queue<int> q;
  pred[0]=0;
  q.push(0);
  while(!q.empty()){
    int v=q.front();
    q.pop();
    for(int i=0;i<int(g[v].size());++i)
      if(flow[v][g[v][i]]<1 && pred[g[v][i]]==-1){
	pred[g[v][i]]=v;
	q.push(g[v][i]);
	if(g[v][i]==n-1)
	  return true;
    } 
  }
  return false;
}

void edmond(const vector<vector<int> >& g, vector<vector<int> >& flow){
  vector<int> pred;
  while(bfs(g,flow,pred)){
    int tmp=n-1;
    while(tmp!=0){
      flow[pred[tmp]][tmp]+=1;
      flow[tmp][pred[tmp]]-=1;
      tmp=pred[tmp];
    }
  }
}

int main(){
  vector<pi> dir;
  dir.push_back(pi(1,0));
  dir.push_back(pi(-1,0));
  dir.push_back(pi(0,1));
  dir.push_back(pi(0,-1));

  int nb;
  cin >> nb;
  while(nb--){

    cin >> s >> a >> m;

    n=2*s*a+2;
    vector<vector<int> > flow(n,vector<int>(n,0));
    vector<vector<int> > g(n);
    
    for(int i=0;i<m;++i){
      int x,y;
      cin >> x >> y;
      --x;--y;
      g[0].push_back(in(x,y));
      g[out(x,y)].push_back(0);
    }

    for(int x=0;x<s;++x){
      g[n-1].push_back(in(x,0));
      g[n-1].push_back(in(x,a-1));
      g[out(x,0)].push_back(n-1);
      g[out(x,a-1)].push_back(n-1);
    }

    for(int y=0;y<a;++y){
      g[n-1].push_back(in(0,y));
      g[n-1].push_back(in(s-1,y));
      g[out(0,y)].push_back(n-1);
      g[out(s-1,y)].push_back(n-1);
    }
    
    for(int x=0;x<s;++x)
      for(int y=0;y<a;++y){
	g[out(x,y)].push_back(in(x,y));
	g[in(x,y)].push_back(out(x,y));
	
	for(int i=0;i<4;++i)
	  if(x+dir[i].first>=0 &&
	     x+dir[i].first<s &&
	     y+dir[i].second>=0 &&
	     y+dir[i].second<a){
	    
	    g[out(x,y)].push_back(in(x+dir[i].first,y+dir[i].second));
	    //g[out(x+dir[i].first,y+dir[i].second)].push_back(in(x,y));
	  }
      }
    
    for(int i=0;i<n;++i){
      sort(g[i].begin(),g[i].end());
      g[i].resize(distance(g[i].begin(),unique(g[i].begin(),g[i].end())));
    }
    
    /*  
    cerr << "Voici le graph " << n << endl;
    for(int i=0;i<n;++i){
      for(int j=0;j<int(g[i].size());++j)
	cerr << g[i][j] << ' ';
      cerr << endl;
    }
    */
	
    edmond(g,flow);
    
    int escape=0;
    for(int i=0;i<int(g[0].size());++i)
      escape+=flow[0][g[0][i]];
    
    //  cerr << escape << endl;

    if(escape!=m)
      cout << "not ";
    cout << "possible\n";
  }
}
