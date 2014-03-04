#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<limits>

using namespace std;

int aux(const vector<vector<pair<int, int> > > & t, int q){
  int n=int(t.size());
  q=min(n,q);
  q=max(0,q);
  vector<vector<int> > dist(q+2, vector<int>(n,numeric_limits<int>::max()));
  dist[0][0]=0;
  
  for(int i=1;i<=q+1;++i){
    for(int j=0;j<n;++j)
      dist[i][j]=dist[i-1][j];
    for(int j=0;j<n;++j)
      for(int k=0;k<int(t[j].size());++k){
	if(dist[i-1][j]!=numeric_limits<int>::max() && dist[i-1][j]+t[j][k].second<dist[i][t[j][k].first])
	  dist[i][t[j][k].first]=dist[i-1][j]+t[j][k].second;
      }
  }
  return dist[q+1][n-1];
}

int main(){
  int cas;
  cin >> cas;
  for(int icas=1;icas<=cas;++icas){
    if(icas!=1) cout << '\n';
    cout << "Scenario #" << icas << '\n';

    int n;
    cin >> n;
    map<string,int> ma;
    for(int i=0;i<n;++i){
      string tmp;
      cin >> tmp;
      ma[tmp]=i;
    }
    int m;
    cin >> m;
    vector<vector<pair<int, int> > > t(n);
    for(int i=0;i<m;++i){
      string a,b;
      int c;
      cin >> a >> b >> c;
      t[ma[a]].push_back(make_pair(ma[b],c));
    }

    int q;
    cin >> q;
    for(int i=0;i<q;++i){
      int tmp;
      cin >> tmp;
      int cost=aux(t,tmp);
      if(cost==numeric_limits<int>::max())
	cout << "No satisfactory flights\n";
      else
	cout << "Total cost of flight(s) is $" << cost << '\n';
    }

  }
}
