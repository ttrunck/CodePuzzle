#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

struct comp{
  bool operator()(pair<int,int> & a, pair<int,int> & b){
    return a.second>b.second;
  };
};

const int MAXI=109;
vector<pair<int,int> > t[MAXI];
int dist[MAXI];

int aux(int s, int T){
  int res=0;
  priority_queue<pair<int,int>, vector<pair<int,int> >, comp> pq;
  pq.push(make_pair(s,0));

  while(!pq.empty()){
    pair<int,int> curr= pq.top();
    pq.pop();
    if(dist[curr.first]!=-1) continue;
    dist[curr.first]=curr.second;
    if(curr.second<=T){
      res++;
      for(int i=0;i<t[curr.first].size();++i)
	if(dist[t[curr.first][i].first]==-1)
	  pq.push(make_pair(t[curr.first][i].first, dist[curr.first]+ t[curr.first][i].second));
    }
  }
  return res;
}

int main(){
  int cas;
  cin >> cas;
  for(int k=0;k<cas;++k){

    for(int i=0;i<MAXI;++i){
      t[i].clear();
      dist[i]=-1;
    }

    int N,E,T,M;
    cin >> N >> E >> T >> M;
    for(int i=0;i<M;++i){
      int a,b,c;
      cin >> a >> b >> c;
      t[b].push_back(make_pair(a,c));
    }

    if(k>0)
      cout << endl;
    cout << aux(E, T) << endl;
  }
}
