#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

typedef pair<int,int> pi;

double dist(const pi& a, const pi& b){
  return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

bool bfs(const vector<vector<int> >& g, const vector<vector<int> >& flow, vector<int>& pred){
  int n=g.size();
  pred.assign(n,-1);
  pred[0]=0;
  queue<int> q;
  q.push(0);
  while(!q.empty()){
    int v=q.front();
    q.pop();
    for(int i=0;i<int(g[v].size());++i)
      if(pred[g[v][i]]==-1 && flow[v][g[v][i]]<1){
	pred[g[v][i]]=v;
	if(g[v][i]==n-1)
	  return true;
	q.push(g[v][i]);
      }
  }
  return false;
}

void edmond(const vector<vector<int> >& g, vector<vector<int> >& flow){
  vector<int> pred;
  while(bfs(g,flow,pred)){
    int tmp=g.size()-1;
    while(tmp!=0){
      flow[pred[tmp]][tmp]+=1;
      flow[tmp][pred[tmp]]-=1;
      tmp=pred[tmp];
    }
  }
}

int main(){
  int nb;
  cin >> nb;
  bool first=true;
  while(nb--){
    if(!first)
      cout << '\n';
    first = false;
    int n,m;
    cin >> n >> m;
    vector<pi> bob(n);
    vector<pi> dog(m);
    for(int i=0;i<n;++i)
      cin >> bob[i].first >> bob[i].second;
    for(int i=0;i<m;++i)
      cin >> dog[i].first >> dog[i].second;
    
    vector<vector<int> > g(1+n+m);
    vector<vector<int> > flow(1+n+m, vector<int>(1+n+m,0));
    
    for(int i=0;i<n-1;++i){
      g[0].push_back(i+1);
      g[i+1].push_back(0);
    }
    for(int i=0;i<m;++i){
      g[n+m].push_back(i+n);
      g[i+n].push_back(n+m);
    }

    for(int i=0;i<n-1;++i)
      for(int j=0;j<m;++j)
	if(dist(bob[i],dog[j])+dist(dog[j],bob[i+1])<2*dist(bob[i],bob[i+1])){
	  g[n+j].push_back(i+1);
	  g[i+1].push_back(n+j);
	}

    /*
    for(int i=0;i<n+m+1;++i){
      for(int j=0;j<int(g[i].size());++j)
	cerr << g[i][j] << ' ';
      cerr << endl;
    }
    */

    edmond(g,flow);

    vector<pi> res;
    for(int i=0;i<n-1;++i){
      res.push_back(bob[i]);
      for(int j=0;j<m;++j)
	if(flow[1+i][n+j]==1){
	  res.push_back(dog[j]);
	  break;
	}
    }
    res.push_back(bob[n-1]);

    cout << res.size() << '\n';
    cout << res[0].first << ' ' << res[0].second;
    for(int i=1;i<int(res.size());++i)
      cout << ' ' << res[i].first << ' ' << res[i].second;
    cout << '\n';
  }
}
