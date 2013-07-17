#include<iostream>
#include<vector>

using namespace std;

void dfs(int s, const vector<vector<int> >& t, vector<int>& res, vector<bool>& seen){
  // cerr << s << endl;
  for(int i=0;i<int(t[s].size());++i)
    if(!seen[t[s][i]]){
      seen[t[s][i]]=true;
      dfs(t[s][i], t, res, seen);
    }
  res.push_back(s);

}

int main(){
  int n, m;
  while(cin >> n >> m && (n||m)){
    vector<vector<int> > t(n);
    for(int i=0;i<m;++i){
      int a,b;
      cin >> a >> b;
      t[a-1].push_back(b-1);
    }

    vector<bool> seen(n, false);
    vector<int> res;
    for(int i=0;i<n;++i)
      if(!seen[i]){
	seen[i]=true;
	dfs(i, t, res, seen);
      }

    cout << res[n-1]+1;
    for(int i=n-2;i>=0;--i)
      cout << ' ' << res[i]+1;
    cout << '\n';

  }
}
