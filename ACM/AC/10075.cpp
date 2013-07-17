#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<map>

using namespace std;

typedef pair<double, double> pf;

const double R=6378;
const double pi=3.141592653589793;

double dist(double lat1, double lon1, double lat2, double lon2, double R){
 double dlon = lon2 - lon1;
 double dlat = lat2 - lat1;
 double a = sin(dlat/2)*sin(dlat/2) + cos(lat1) * cos(lat2) * sin(dlon/2)*sin(dlon/2);
 return R* 2 * atan2(sqrt(a), sqrt(1-a)) ;
}

double dij(int start, int stop, const vector<vector<pair<int, int> > > & t){
  vector<int> d(t.size(), -1);
  priority_queue<pair<double, int> > q;
  q.push(make_pair(0, start));
  while(!q.empty()){
    pair<int, int> curr=q.top();
    //  cerr << "curr " << curr.first << ' ' << curr.second << endl;
    if(curr.second==stop) return -curr.first;
    q.pop();
    d[curr.second]=-curr.first;
    for(int i=0;i<int(t[curr.second].size());++i){
      if(d[t[curr.second][i].second]==-1){
	q.push(make_pair(curr.first-t[curr.second][i].first, t[curr.second][i].second));
      }
    }
  }
  return -1;
}

int main(){
  int n,M,q;
  int icase=1;
  while(cin >> n >> M >> q && (n||M||q)){
    if(icase>1) cout << '\n';
    cout << "Case #" << icase++ << '\n';
    map<string, int> m;
    vector<pf> t(n);
    for(int i=0;i<n;++i){
      string tmp;
      double a,b;
      cin >> tmp >> a >> b;
      m[tmp]=i;
      t[i]=pf(a,b);
    }

    vector<vector<pair<int, int> > > g(n);
    for(int i=0;i<M;++i){
      string s1,s2;
      cin >> s1 >> s2;
      int n1=m[s1], n2=m[s2];
      double d=dist(t[n1].first*pi/180, t[n1].second*pi/180, t[n2].first*pi/180, t[n2].second*pi/180, R);
      g[n1].push_back(make_pair(int(d+0.5), n2));
      // g[n2].push_back(make_pair(-d, n1));
    }

    for(int i=0;i<q;++i){
      string s1,s2;
      cin >> s1 >> s2;
      int tmp=dij(m[s1],m[s2],g);
      if(tmp<0)
	cout << "no route exists\n";
      else
	cout << tmp << " km\n";
    }
  }
}
