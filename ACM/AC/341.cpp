#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

typedef pair<int,int> pi;

struct triple{
  int ville, prix, pred;
  triple(int a,int b, int c):ville(a),prix(b),pred(c){};
};

struct myCompare{
  bool operator()(const triple & a, const triple & b){
    return a.prix > b.prix;
  }
};

int dijkstra(int start, const vector<vector<pi> > & t, int stop, vector<int> & trajet){
  vector<int> pred(t.size(),-1);
  vector<int> dist(t.size(),-1);
  priority_queue<triple, vector<triple>, myCompare> q;
  q.push(triple(start,0,start));
  while(!q.empty()){
    const triple curr=q.top();
    // cerr << curr.ville << ' ' << curr.prix << ' ' << curr.pred << endl;
    q.pop();
    if(dist[curr.ville]!=-1) continue;
    dist[curr.ville]=curr.prix;
    pred[curr.ville]=curr.pred;
    if(curr.ville==stop) break;
    for(int i=0;i<int(t[curr.ville].size());++i)
      if(dist[t[curr.ville][i].first]==-1)
	q.push(triple(t[curr.ville][i].first, t[curr.ville][i].second + curr.prix, curr.ville));
  }

  // cerr << "Fin du calcul" << endl;
  /*
  for(int i=0;i<int(pred.size());++i)
    cerr << pred[i] << ' ';
  cerr << endl;

 for(int i=0;i<int(dist.size());++i)
    cerr << dist[i] << ' ';
  cerr << endl;
  */
  int curr=stop;
  do{
    //   cerr << curr << endl;
    trajet.push_back(curr);
    curr=pred[curr];
  }while(curr!=start);
  trajet.push_back(start);

  // cerr << "Fin du trajet" << endl;

  for(int i=0;2*i<int(trajet.size());++i)
    swap(trajet[i], trajet[int(trajet.size())-1-i]);

  return dist[stop];
}

int main(){
  ios::sync_with_stdio(false);
  int icase=1;
  int n;
  while(cin >> n && n){
    vector<vector<pi> > t(n);
    for(int i=0;i<n;++i){
      int k;
      cin >> k;
      for(int j=0;j<k;++j){
	int a,b;
	cin >> a >> b;
	t[i].push_back(pi(a-1,b));
      }
    }

    int start,stop;
    cin >> start >> stop;
    start--;stop--;
    vector<int> trajet;

    int dist=dijkstra(start, t, stop, trajet);
    
    cout << "Case " << icase++ << ": Path =";
    for(int i=0;i<int(trajet.size());++i)
      cout << ' ' << trajet[i]+1;
    cout << "; " << dist << " second delay\n";
  }
}
