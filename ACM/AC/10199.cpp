#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<set>

using namespace std;

void dfs(int s, const vector<vector<int> >& t, vector<int>& parent, 
	 vector<int>& dfs_low, vector<int>& dfs_num, set<int>& res, int& compt,
	 int root, int& fils){
  
  dfs_low[s]=dfs_num[s]=compt++;
  
  for(int i=0;i<int(t[s].size());++i){
    if(parent[t[s][i]]==-1){
      parent[t[s][i]]=s;
      if(s==root)
	++fils;
      dfs(t[s][i], t,parent,dfs_low,dfs_num,res,compt,root,fils);
      if(dfs_low[t[s][i]]>=dfs_num[s])
	res.insert(s);
      dfs_low[s]=min(dfs_low[s], dfs_low[t[s][i]]);
    }
    else if(parent[s]!=t[s][i]){
      dfs_low[s]=min(dfs_low[s], dfs_num[t[s][i]]);
    }
  }

}

int main(){
  int icase=1;
  bool first=true;
  int n;
  while(cin >> n && n){
    if(!first)
      cout << '\n';
    first=false;
    map<string, int> to_ver;
    vector<string> from_ver(n);
    vector<vector<int> > t(n);
    for(int i=0;i<n;++i){
      string s;
      cin >> s;
      to_ver[s]=i;
      from_ver[i]=s;
    }
    int m;
    cin >> m;
    for(int i=0;i<m;++i){
      string a,b;
      cin >> a >> b;
      t[to_ver[a]].push_back(to_ver[b]);
      t[to_ver[b]].push_back(to_ver[a]);
    }

    vector<int> parent(n, -1);
    vector<int> dfs_low(n);
    vector<int> dfs_num(n);
    set<int> vres;
    int compt=0;

    for(int i=0;i<n;++i)
      if(parent[i]==-1){
	parent[i]=i;
	int filsroot=0;
	dfs(i, t, parent, dfs_low, dfs_num, vres, compt, i, filsroot);
	if(filsroot>1)
	  vres.insert(i);
	else
	  vres.erase(i);
      }

    vector<string> res;
    for(set<int>::iterator it=vres.begin();it!=vres.end();++it)
      res.push_back(from_ver[*it]);

    sort(res.begin(), res.end());


    cout << "City map #" << icase++ << ": " << res.size() << " camera(s) found\n";
    for(int i=0;i<int(res.size());++i)
      cout << res[i] << '\n';


  }
}
