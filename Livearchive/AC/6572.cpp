#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <complex>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

struct triple{
  int n,x,y;
  triple(int a=0, int b=0, int c=0): n(a), x(b), y(c){}; 
};

const int INT_MAX = 1000000000;

#define forn(i, n) for (int i = 0; i < (n); ++i)

// Return true iff contains negative cycle.
// r[i][j] = next vertex in shortest path from i to j.
bool royWarshall(vector<vector<double> > &g, vector<vector<int> > &r) {
	int n = g.size();
	forn(i, n)
		forn(j, n)
			r[i][j] = (g[i][j] == INT_MAX ? i : j);
	forn(k, n)
		forn(i, n)
			forn(j, n) {
				if (g[i][k] == INT_MAX || g[k][j] == INT_MAX) continue;
				if (g[i][k] + g[k][j] < g[i][j]) {
					g[i][j] = g[i][k] + g[k][j];
					r[i][j] = r[i][k];
				}
			}
	forn(i, n)
		if (g[i][i] < 0) return true;
	return false;
}

int main(){
  int N,M;
  bool first=true;
  while(cin >> N >> M){
    if(!first)
      cout << '\n';
    first=false;

  vector<vector<double> > dist(N, vector<double>(N, INT_MAX));
  
  for(int i=0;i<N;++i)
    dist[i][i]=0;

  vector<triple> place(N);
  for(int i=0;i<N;++i)
    cin >> place[i].n >> place[i].x >> place[i].y;
  
  for(int i=0;i<N;++i)
    place[i].n = 5*place[i].n;

  for(int i=0;i<M;++i){
    int a,b;
    string s;
    cin >> a >> b >> s;

    if(s=="lift"){
      dist[a][b]=min(dist[a][b], 1.);
      dist[b][a]=min(dist[b][a], 1.);
    }
    else if(s=="escalator"){
      dist[a][b]=min(dist[a][b],1.);
      dist[b][a]=min(dist[b][a], 3*sqrt(
				      (place[a].n-place[b].n)*(place[a].n-place[b].n) +
				      (place[a].x-place[b].x)*(place[a].x-place[b].x) +
				      (place[a].y-place[b].y)*(place[a].y-place[b].y)));
    }    
    else{
      dist[a][b]=min(dist[a][b], sqrt(
				      (place[a].n-place[b].n)*(place[a].n-place[b].n) +
				      (place[a].x-place[b].x)*(place[a].x-place[b].x) +
				      (place[a].y-place[b].y)*(place[a].y-place[b].y)));
      dist[b][a]=min(dist[a][b],dist[b][a]);
    }
  }

 vector<vector<int> > r(N, vector<int>(N));
  royWarshall(dist, r);
 
  int Q;
  cin >> Q;
  for(int i=0;i<Q;++i){
    int a, b;
    cin >> a >> b;
    cout << a;
    while(a!=b){
      a=r[a][b];
      cout << ' ' << a;
    }
    cout << '\n';
  }
  }
}
