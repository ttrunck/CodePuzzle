#include<iostream>
#include<vector>
#include<limits>

using namespace std;

const int INF=numeric_limits<int>::max();

int main(){
  int nbcase;
  cin >> nbcase;
  for(int icase=1;icase<=nbcase;++icase){
    cout << "Case " << icase << ": ";
    int n,m;
    cin >> n >> m;
    vector<vector<int> > t(n, vector<int>(n, INF));
    for(int i=0;i<n;++i)
      t[i][i]=0;

    for(int i=0;i<m;++i){
      int a,b;
      cin >> a >> b;
      t[a][b]=1;
      t[b][a]=1;
    }

    for(int k=0;k<n;++k)
      for(int i=0;i<n;++i)
	for(int j=0;j<n;++j)
	  if(t[i][k]!=INF && t[k][j]!=INF)
	    t[i][j]=min(t[i][j], t[i][k]+t[k][j]);

    int s,e;
    cin >> s >> e;
    int res=0;
    for(int i=0;i<n;++i)
      res=max(res,t[s][i]+t[i][e]);
    cout << res << '\n';
  }
}
