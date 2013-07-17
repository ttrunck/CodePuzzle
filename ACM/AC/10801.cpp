#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<sstream>
#include<string>

using namespace std;

typedef pair<int,int> pi;

int n;

struct triple{
  int ville, prix, pred;
  triple(int a,int b, int c):ville(a),prix(b),pred(c){};
};

struct myCompare{
  bool operator()(const triple & a, const triple & b){
    return a.prix > b.prix;
  }
};

int dijkstra(int start, const vector<vector<pi> > & t, int stop){
  vector<int> dist(t.size(),-1);
  priority_queue<triple, vector<triple>, myCompare> q;
  for(int i=0;i<n;++i)
    q.push(triple(start+100*i,0,start+100*i));
  while(!q.empty()){
    const triple curr=q.top();
    q.pop();
    if(dist[curr.ville]!=-1) continue;
    // cerr << curr.ville << ' ' << curr.prix << ' ' << curr.pred << endl;
    dist[curr.ville]=curr.prix;
    if(curr.ville%100==stop) return curr.prix;
    for(int i=0;i<int(t[curr.ville].size());++i)
      if(dist[t[curr.ville][i].first]==-1)
	q.push(triple(t[curr.ville][i].first, t[curr.ville][i].second + curr.prix, curr.ville));
  }
  return -1;
}

int main(){
  ios::sync_with_stdio(false);
  int k;
  while(cin >> n >> k){
    vector<int> T(n);
    for(int i=0;i<n;++i)
      cin >> T[i];
    
    vector<vector<pi> > t(n*100);
    for(int i=0;i<100;++i)
      for(int j=0;j<n;++j)
	for(int k=j+1;k<n;++k){
	t[i+k*100].push_back(pi(i+j*100,60));
	t[i+j*100].push_back(pi(i+k*100,60));
      }
	

    cin.ignore();
    for(int I=0;I<n;++I){
      string s;
      getline(cin, s);
      stringstream ss(s);
      vector<int> tmp;
      int paf;
      while(ss >> paf)
	tmp.push_back(paf+I*100);
      for(int i=0;i<int(tmp.size());++i)
	for(int j=i+1;j<int(tmp.size());++j){
	  t[tmp[i]].push_back(pi(tmp[j],T[I]*(tmp[j]-tmp[i])));
	  t[tmp[j]].push_back(pi(tmp[i],T[I]*(tmp[j]-tmp[i])));
	}
    }
    
    
    
    int dist=dijkstra(0,t,k);
    if(dist==-1)
      cout << "IMPOSSIBLE\n";
    else cout << dist << '\n';
  }
}
