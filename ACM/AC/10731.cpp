#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool comp(const vector<int>& a, const vector<int>& b){
  return a[0]<b[0] ;
}

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
  int n;
  bool first=true;
  while(cin >> n && n){
    if(!first)
      cout << '\n';
    first=false;
    vector<vector<int> > t(26);
    vector<bool> exist(26, false);
    for(int i=0;i<n;++i){
      char a,b,c,d,e,f;
      cin >> a >> b >> c >> d >> e >> f;
      t[f-'A'].push_back(a-'A');
      t[f-'A'].push_back(b-'A');
      t[f-'A'].push_back(c-'A');
      t[f-'A'].push_back(d-'A');
      t[f-'A'].push_back(e-'A');
      exist[a-'A']=true;
      exist[b-'A']=true;
      exist[c-'A']=true;
      exist[d-'A']=true;
      exist[e-'A']=true;
      exist[f-'A']=true;
    }

    vector<int> res(26);
    vector<int> dfs_num(26,-1);
    vector<int> dfs_low(26);
    vector<bool> seen(26, false);
    int nb=0;
    int nbSCC=0;
    vector<int> S;
    
    for(int i=0;i<26;++i)
      if(exist[i] && dfs_num[i]==-1)
	tarjanSCC(i,t,dfs_low, dfs_num, nb, S, nbSCC, res, seen);

    vector<vector<int> > r(nbSCC);
    for(int i=0;i<26;++i)
      if(exist[i])
	r[res[i]-1].push_back(i);

    sort(r.begin(), r.end(), comp);

    for(int i=0;i<nbSCC;++i){
      cout << char('A'+r[i][0]);
      for(int j=1;j<int(r[i].size());++j)
	cout << ' ' << char('A'+r[i][j]);
      cout << '\n';
    }

  }
}
