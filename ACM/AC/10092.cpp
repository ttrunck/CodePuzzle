#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int, int> pi;

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
  int n,p;
  while(cin >> p >> n && (p || n)){
    vector<int> pp(p);
    for(int i=0;i<p;++i)
      cin >> pp[i];

    vector<vector<int> > g(2+n+p);
    vector<vector<int> > flow(2+n+p, vector<int>(2+n+p));
    vector<vector<int> > capa(2+n+p, vector<int>(2+n+p));
    for(int i=0;i<n;++i){
      g[0].push_back(1+i);
      g[1+i].push_back(0);
      capa[0][1+i]=1;
      capa[1+i][0]=1;
    }

    for(int i=0;i<p;++i){
      g[n+p+1].push_back(n+i+1);
      g[n+i+1].push_back(n+p+1);
      capa[n+p+1][n+i+1]=pp[i];
      capa[n+i+1][n+p+1]=pp[i];
    }

    for(int i=0;i<n;++i){
      int nb;
      cin >> nb;
      for(int j=0;j<nb;++j){
	int cat;
	cin >> cat;
	--cat;
	g[i+1].push_back(1+n+cat);
	g[1+n+cat].push_back(i+1);
	capa[i+1][1+n+cat]=1;
	//	capa[1+n+cat][i+1]=1;
      }
    }

    /*
    for(int i=0;i<n+p+2;++i){
      for(int j=0;j<int(g[i].size());++j)
	cerr << g[i][j] << ',' << capa[i][g[i][j]] << ' ';
      cerr << endl;
    }
    */
    int res = edmond(g, flow, capa);

    int tot=0;
    for(int i=0;i<p;++i)
      tot+=pp[i];

    if(res==tot){
      cout << 1 << '\n';
      for(int i=0;i<p;++i){
	int tmp=0;
	bool first = true;
	for(int j=0;j<n;++j)
	    if(flow[1+j][1+n+i]==1){
	      tmp++;
	      if(tmp>pp[i])
		while(1);
	      if(!first)
		cout << ' ';
	      first=false;
	      cout << 1+j;
	    }
	cout << '\n';      
      }
    }
    else
      cout << 0 << '\n';

  }
}

