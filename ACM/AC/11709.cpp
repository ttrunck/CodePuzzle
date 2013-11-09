#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

void tarjanSCC(int u, const vector<vector<int> >& g, vector<int>& dfs_low,
	       vector<int>& dfs_num, int& nb, vector<int>& S, int& nbSCC, 
	       vector<int>& res, vector<bool>& seen){
  dfs_low[u]=dfs_num[u]=nb++;
  S.push_back(u);
  seen[u]=true;

  for(int i=0;i<int(g[u].size());++i){
    int v=g[u][i];
    if(dfs_num[v]==-1)
      tarjanSCC(v,g,dfs_low, dfs_num, nb, S, nbSCC, res, seen);
    if(seen[v])
      dfs_low[u]=min(dfs_low[u], dfs_low[v]);
  }

  if(dfs_low[u] == dfs_num[u]){
    ++nbSCC;
    while(1){
      int v=S.back();S.pop_back();seen[v]=false;
      res[v]=nbSCC;
      if(u==v) break;
    }
  }
}

int main(){
  int n, m;
  while(cin >> n >> m && (n||m)){
    cin.ignore();
    map<string, int> ms;
    for(int i=0;i<n;++i){
      string s;
      getline(cin, s);
      ms[s]=i;
    }

    vector<vector<int> > t(n);

    for(int i=0;i<m;++i){
      string a,b;
      getline(cin, a);
      getline(cin, b);
      t[ms[a]].push_back(ms[b]);
    }

 vector<int> res(n);
    vector<int> dfs_num(n,-1);
    vector<int> dfs_low(n);
    vector<bool> seen(n, false);
    int nb=0;
    int nbSCC=0;
    vector<int> S;
    
    for(int i=0;i<n;++i)
      if(dfs_num[i]==-1)
	tarjanSCC(i,t,dfs_low, dfs_num, nb, S, nbSCC, res, seen);

    cout << nbSCC << '\n';

  }
}
