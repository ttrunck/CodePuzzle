#include<iostream>
#include<vector>
#include<string>
#include<limits>

using namespace std;

const int INF=numeric_limits<int>::max();

typedef pair<int, int> ii;

int main(){
  string s;
  while(getline(cin, s)){
    cout << s << '\n';

    int n, m;
    cin >> n >> m;

    vector<vector<ii> > t(m*(n-1));

    for(int k=0;k<m*m*(n-1);++k){
      int tmp;
      cin >> tmp;
      t[k/m].push_back(ii((k/m+1)*m+(k%m),tmp));
    }
    getline(cin, s);
    
    vector<int> dist(m*(n-1),INF);

    for(int i=(n-2)*m;i<m*(n-1);++i)
      for(int j=0;j<m;++j)
	dist[i]=min(dist[i],2+t[i][j].second);

    for(int k=n-3;k>=0;--k)
      for(int i=0;i<m;++i)
	for(int j=0;j<m;++j)
	  dist[k*m+i]=min(dist[k*m+i], 2+t[k*m+i][j].second + dist[(k+1)*m+j]);

    int res=INF;
    for(int i=0;i<m;++i)
      res=min(res, dist[i]);

    cout << res << '\n';

  }
}
