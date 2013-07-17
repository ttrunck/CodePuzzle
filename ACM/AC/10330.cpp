#include <vector>
#include <iostream>
#include<queue>
#include<climits>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)

struct EdmondsKarp {
	vector<vector<int> > adj, capa, flow;
	vector<int> prev;
	int flowSize;

	EdmondsKarp(int n = 0) :
		adj(n), capa(n, vector<int> (n, 0)), flow(n, vector<int> (n, 0)), flowSize(0) {}

	void findAgumentingPath(int source, int target) {
		queue<int> file;
		prev.assign(adj.size(), -1);
		prev[source] = -2;
		file.push(source);
		while (not file.empty()) {
			int x = file.front(); file.pop();
			forn(i, adj[x].size()) {
				int y = adj[x][i];
				if (prev[y] == -1 && capa[x][y] - flow[x][y] > 0) {
					prev[y] = x;
					file.push(y);
					if (y == target)
					  return;
				}
			}
		}
	}

	void augmentFlow(int target) {
		int delta = INT_MAX;
		for (int y = target, x = prev[target]; x >= 0; y = x, x = prev[x])
			delta = min(delta, capa[x][y] - flow[x][y]);
		for (int y = target, x = prev[target]; x >= 0; y = x, x = prev[x]) {
			flow[x][y] += delta;
			flow[y][x] -= delta;
		}
		flowSize += delta;
	}

	int maxFlow(int source, int target) {
		int n = adj.size(); flowSize = 0;
		flow.assign(n, vector<int> (n, 0));
		while (true) {
			findAgumentingPath(source, target);
			if (prev[target] == -1) break;
			augmentFlow(target);
		}
		return flowSize;
	}
};

int main(){
  int n;
  while(cin >> n){
    EdmondsKarp EK(2*n+2);

    for(int i=0;i<n;++i){
      int tmp;
      cin >> tmp;
      EK.adj[2*i].push_back(2*i+1);
      EK.adj[2*i+1].push_back(2*i);
      EK.capa[2*i][2*i+1]=tmp;
    }

    int edge;
    cin >> edge;
    for(int i=0;i<edge;++i){
      int a,b,c;
      cin >> a >> b >> c;
      --a;--b;
      EK.adj[2*a+1].push_back(2*b);
      EK.adj[2*b].push_back(2*a+1);
      EK.capa[2*a+1][2*b]=c;
    }

    int in, out;
    cin >> in >> out;
    for(int i=0;i<in;++i){
      int tmp;
      cin >> tmp;
      --tmp;
      EK.adj[2*n].push_back(2*tmp);
      EK.adj[2*tmp].push_back(2*n); 
      EK.capa[2*n][2*tmp]=INT_MAX;
    }

    for(int i=0;i<out;++i){
      int tmp;
      cin >> tmp;
      --tmp;
      EK.adj[2*tmp+1].push_back(2*n+1);
      EK.adj[2*n+1].push_back(2*tmp+1);
      EK.capa[2*tmp+1][2*n+1]=INT_MAX;
    }
    cout << EK.maxFlow(2*n, 2*n+1) << '\n';
  }
}
