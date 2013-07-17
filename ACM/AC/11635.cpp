#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
#include<cstdio>

using namespace std;

int const N=10009;
int const T=600;

typedef pair<int, int> tup;

int n,h;
vector<int> hotel;
vector<tup> pregraph[N];
vector<int> graph[N];

void init(){
  hotel.clear();
  hotel.push_back(1);
  hotel.push_back(n);
  for(int i=0;i<=n;++i)
    pregraph[i].clear();
  for(int i=0;i<=n;++i)
    graph[i].clear();
}

int visite[N];
int v[N];

struct comp{
  bool operator()(tup a, tup b){
    return a.second>b.second;
  }
};

void compute(int dep){
  for(int i=0;i<=n;++i)
    visite[i]=-1;
  priority_queue< tup, vector<tup>, comp> q;
  q.push(make_pair(dep,0));
  while(!q.empty()){
    tup curr=q.top();
    q.pop();
    if(curr.second>T) break;
    if(visite[curr.first]!=-1) continue;
    visite[curr.first]=curr.second;
    if(curr.first!=dep && curr.second <=T && count(hotel.begin(), hotel.end(), curr.first)>0)
      graph[dep].push_back(curr.first);
    for(int i=0;i<pregraph[curr.first].size();++i)
      if(visite[pregraph[curr.first][i].first]==-1 && curr.second+pregraph[curr.first][i].second<=T)
	q.push(
		    make_pair(
			      pregraph[curr.first][i].first,
			      curr.second+pregraph[curr.first][i].second));
  }
}

int dist(int dep, int fin){
for(int i=0;i<=n;++i)
    v[i]=-1;
  queue<tup> q;
  q.push(make_pair(dep,0));
  while(!q.empty()){
    tup curr=q.front();
    q.pop();
    if(v[curr.first]!=-1) continue;
    v[curr.first]=curr.second;
    if(curr.first==fin)
      return curr.second-1;
    for(int i=0;i<graph[curr.first].size();++i)
      if(v[graph[curr.first][i]]==-1)
	q.push(
		    make_pair(
			      graph[curr.first][i],
			      v[curr.first]+1));
  }
  return -1;
}

void printg(){
  for(int i=1;i<=n;++i){
    cout << i << ": ";
    for(int j=0;j<pregraph[i].size();++j)
      cout << pregraph[i][j].first << ' ';
    cout << endl;
  }
}

void print(){
  for(int i=0;i<hotel.size();++i){
    cout << hotel[i] << ": ";
    for(int j=0;j<graph[hotel[i]].size();++j)
      cout << graph[hotel[i]][j] << ' ';
    cout << endl;
  }
}

int main(){
  cin >> n;
  while(n!=0){
    init();
    cin >> h;
    for(int i=0;i<h;++i){
      int tmp;
      cin >> tmp;
      hotel.push_back(tmp);
    }
    int m;
    cin >> m;
    for(int i=0;i<m;++i){
      int a, b, d;
      scanf("%d %d %d", &a, &b, &d);
      pregraph[a].push_back(make_pair(b,d));
      pregraph[b].push_back(make_pair(a,d));
    }
    
    for(int i=0;i<hotel.size();++i)
      compute(hotel[i]);

    cout << dist(1,n) << endl;
    cin >> n;
  }
}
