#include<iostream>
#include<vector>
#include<queue>

using namespace std;

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
  int nb;
  cin >> nb;
  for(int icase=1;icase<=nb;++icase){
    cout << "Case " << icase << ": ";
    int n,m;
    cin >> n;
    vector<int> data1(n);
    for(int i=0;i<n;++i)
      cin >> data1[i];
    cin >> m;
    vector<int> data2(m);
    for(int i=0;i<m;++i)
      cin >> data2[i];

    vector<vector<int> > g(2+n+m);
    vector<vector<int> > flow(2+n+m, vector<int>(2+n+m));
    vector<vector<int> > capa(2+n+m, vector<int>(2+n+m));
    
    for(int i=0;i<n;++i){
      g[0].push_back(1+i);
      capa[0][i+1]=1;
    }

    for(int i=0;i<m;++i){
      g[1+n+i].push_back(1+n+m);
      capa[1+n+i][1+n+m]=1;
    }

    for(int i=0;i<n;++i)
      for(int j=0;j<m;++j)
	if((data1[i]==data2[j]) || (data1[i]!=0 && data2[j]%data1[i]==0)){
	  g[1+i].push_back(1+n+j);
	  g[1+n+j].push_back(1+i);
	  capa[1+i][1+n+j]=1;
	}

    cout << edmond(g,flow,capa) << '\n';
  }
}
