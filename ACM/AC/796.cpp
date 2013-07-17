#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> pi;

void dfs(int s, const vector<vector<int> >& t, vector<int>& parent, 
	 vector<int>& dfs_low, vector<int>& dfs_num, vector<pi>& res, int& compt){
  
  dfs_low[s]=dfs_num[s]=compt++;
  
  for(int i=0;i<int(t[s].size());++i){
    if(parent[t[s][i]]==-1){
      parent[t[s][i]]=s;
      dfs(t[s][i], t,parent,dfs_low,dfs_num,res,compt);
      if(dfs_low[t[s][i]]>dfs_num[s])
	res.push_back(pi(min(s,t[s][i]), max(s,t[s][i])));
      dfs_low[s]=min(dfs_low[s], dfs_low[t[s][i]]);
    }
    else if(parent[s]!=t[s][i]){
      dfs_low[s]=min(dfs_low[s], dfs_num[t[s][i]]);
    }
  }

}

int main(){
  int n;
  while(cin >> n){
    vector<vector<int> > t(n);
    for(int i=0;i<n;++i){
      int server, nb;
      char tmp;
      cin >> server >> tmp >> nb >> tmp;
      for(int j=0;j<nb;++j){
	int client;
	cin >> client;
	t[server].push_back(client);
      }
    }

    vector<int> parent(n, -1);
    vector<int> dfs_low(n);
    vector<int> dfs_num(n);
    vector<pi> res;
    int compt=0;

    for(int i=0;i<n;++i)
      if(parent[i]==-1){
	parent[i]=i;
	dfs(i, t, parent, dfs_low, dfs_num, res, compt);
      }
    
    sort(res.begin(), res.end());

    cout << res.size() << " critical links\n";
    for(int i=0;i<int(res.size());++i)
      cout << res[i].first << " - " << res[i].second << '\n';
    cout << '\n';
  }
}
