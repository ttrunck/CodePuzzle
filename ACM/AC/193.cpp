#include<iostream>
#include<vector>

using namespace std;

int n, k;
int gres;
vector<bool> gcol;

int aux(const vector<vector<int> > & g, vector<bool> & v, vector<bool> & col){
  int node=0;
  while(node<n && v[node]) node++;
  if(node>=n){
    int tmp=0;
    for(int i=0;i<int(col.size());++i)
      if(col[i])
	tmp++;
    if(tmp>gres){
      gres=tmp;
      gcol=col;
    }
 return 0;
  }

  bool poss=true;
  for(int i=0;i<int(g[node].size()) && poss;++i)
    poss=poss&&!col[g[node][i]];

  
  v[node]=true;
  int res=aux(g,v,col);
  v[node]=false;

  if(poss){
    //  cerr << node << " Je suis ici\n";
    v[node]=true;
    col[node]=true;
    int tmp=aux(g,v,col)+1;
    v[node]=false;
    col[node]=false;
    res=max(tmp,res);
  }

  return res;
}


int main(){
  int cas;
  cin >> cas;
  while(cas--){
    gres=0;
    gcol.clear();
    cin >> n >> k;
    vector<bool> visited(n,false);
    vector<vector<int> > g(n);
    for(int i=0;i<k;++i){
      int a,b;
      cin >> a >> b;
      a--;b--;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    vector<bool> col(n,false);
   int res=aux(g, visited, col);
    cout << res << endl;
    bool first=true;
    for(int i=0;i<int(gcol.size());++i){
      if(gcol[i]){
	if(!first)
	  cout << ' ';
	first=false;
	cout << i+1;
      }
    }
    cout << endl;
  }
}
