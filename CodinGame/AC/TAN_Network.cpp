#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<cmath>
#include<limits>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;

const double PI = atan(1)*4;
const double INF = numeric_limits<double>::max();

typedef pair<int, double> vertex;
typedef pair<double, double> pf;

double conv(string & s){
  double res;
  stringstream(s) >> res;
  return res;
}

double dist(pf &p1, pf& p2){
  double lon1=p1.first*PI/180, lat1=p1.second*PI/180;
  double lon2=p2.first*PI/180, lat2=p2.second*PI/180;
  double x=(lon2-lon1)*cos((lat1+lat2)/2);
  double y=lat2-lat1;
  return sqrt(x*x+y*y)*6371;
}

struct edge {
  int x, y;
  double w;
  edge(int a=0, int b=0, double c=0): x(a), y(b), w(c) {}
  bool operator< (const edge &e) const {
    return w > e.w;
  }
};

void dijkstra(int s, vector<vector<vertex> > &g, vector<int> &pred, vector<double> &dist){
  priority_queue<edge> q;
  q.push(edge(s,s,0));
  while(!q.empty()){
    edge e = q.top();
    q.pop();
    if (pred[e.y]!=-1) continue;
    pred[e.y] = e.x;
    dist[e.y] = e.w;
    for(vertex v:g[e.y]){
      edge f(e.y, v.first, e.w + v.second);
      if (f.w < dist[f.y]) q.push(f);
    }
  }
}

int main(){
  string start, stop;
  getline(cin, start);
  getline(cin, stop);
  int N;
  cin >> N;
  cin.ignore();
  map<string, int> id_to_n;
  vector<string> n_to_id;
  map<string, string> id_to_name;
  vector<pf> pos;

  for(int i=0;i<N;++i){
    string s;
    getline(cin, s);
    stringstream ss(s);
    string id, name, tmp, slon, slat;
    getline(ss, id, ',');
    getline(ss, name, ',');
    getline(ss, tmp, ',');
    getline(ss, slat, ',');
    getline(ss, slon, ',');

    id_to_n[id]=i;
    n_to_id.push_back(id);
    id_to_name[id]=name.substr(1, name.size()-2);
    pos.push_back(pf(conv(slon), conv(slat)));
  }

  vector<vector<vertex> > graph(N);
  int M;
  cin >> M;
  for(int i=0;i<M;++i){
    string id1, id2;
    cin >> id1 >> id2;
    int n1=id_to_n[id1];
    int n2=id_to_n[id2];
    graph[n1].push_back(vertex(n2, dist(pos[n1], pos[n2])));
  }

  vector<int> pred(graph.size(),-1);
  vector<double> dist_vec(graph.size(), INF);

  dijkstra(id_to_n[start], graph, pred, dist_vec);

  if(pred[id_to_n[stop]]==-1)
    cout << "IMPOSSIBLE\n";
  else{
  vector<int> res;
  int curr=id_to_n[stop];
  while(curr!=id_to_n[start]){
    res.push_back(curr);
    curr=pred[curr];
  }
  res.push_back(curr);
  reverse(begin(res), end(res));

  for(int i:res)
    cout << id_to_name[n_to_id[i]] << '\n';
  }
}
