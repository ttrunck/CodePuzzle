#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int taille(const string& s){
  if(s=="XS")
    return 0;
  if(s=="S")
    return 1;
  if(s=="M")
    return 2;
  if(s=="L")
    return 3;
  if(s=="XL")
    return 4;
  return 5;
}

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
  while(nb--){
    int n,m;
    cin >> n >> m;

    vector<vector<int> > g(2+6+m);
    vector<vector<int> > flow(8+m,vector<int>(8+m));
    vector<vector<int> > capa(8+m,vector<int>(8+m));

    for(int i=0;i<m;++i){
      g[0].push_back(1+i);
      g[1+i].push_back(0);
      capa[0][i+1]=1;
    }

    for(int i=0;i<6;++i){
      g[7+m].push_back(1+m+i);
      g[1+m+i].push_back(7+m);
      capa[1+m+i][7+m]=n/6;
    }

    for(int i=0;i<m;++i)
      for(int j=0;j<2;++j){
	string s;
	cin >> s;
	g[1+i].push_back(taille(s)+1+m);
	g[taille(s)+1+m].push_back(i+1);
	capa[i+1][taille(s)+1+m]=1;
    }

    int res = edmond(g,flow,capa);
    if(res==m)
      cout << "YES\n";
    else
      cout << "NO\n";

  }
}
