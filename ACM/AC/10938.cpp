#include<iostream>
#include<vector>

using namespace std;

void dfs(int s, int e, const vector<vector<int> >& g, vector<int>& pred){
  if(s==e) return;
  for(int i=0;i<int(g[s].size());++i)
    if(pred[g[s][i]]==-1){
      pred[g[s][i]]=s;
      dfs(g[s][i], e, g, pred);
    }
}

int main(){
  int n;
  while(cin >> n && n){
    vector<vector<int> > g(n);
    for(int i=0;i<n-1;++i){
      int a, b;
      cin >> a >> b;
      g[a-1].push_back(b-1);
      g[b-1].push_back(a-1);
    }
    int nb;
    cin >> nb;
    while(nb--){
      int s,e;
      cin >> s >> e;
      s--;e--;
      vector<int> pred(n,-1);
      dfs(s,e,g,pred);
      
      vector<int> chemin;
      /*  
      for(auto i:pred)
	cerr << i << ' ';
      cerr << endl;
      */
      while(e!=s){
	chemin.push_back(e);
	e= pred[e];
      }
      chemin.push_back(e);

      if(int(chemin.size())%2==0){
	int p=chemin[chemin.size()/2-1]+1;
	int r=chemin[chemin.size()/2]+1;
	cout << "The fleas jump forever between " << min(p,r) << " and " << max(p,r) << ".\n";

      }
      else
	cout << "The fleas meet at " << chemin[chemin.size()/2]+1 << ".\n";
    }
  }
}
