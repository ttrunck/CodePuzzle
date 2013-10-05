#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

typedef pair<int, int> pi;

struct Bipartite {
  vector<vector<int> > adjLeft;
  vector<int> matchLeft, matchRight;
  vector<bool> visited;
  int matchingSize;

  Bipartite(int p = 0, int q = 0) :
    adjLeft(p), matchLeft(p, -1), matchRight(q, -1), matchingSize(0) {}
  
  bool depthFirstSearch(int x) {
    if (visited[x]) return false;
    visited[x] = true;
    for(int y:adjLeft[x]){
      int z = matchRight[y];
      if (z < 0 || depthFirstSearch(z)) {
	matchRight[y] = x;
	matchLeft[x] = y;
	return true;
      }
    }
    return false;
  }

  bool findAgumentingPath(void) {
    visited.assign(adjLeft.size(), false);
    for(int i=0;i< int(adjLeft.size());++i)
      if (matchLeft[i] == -1 && depthFirstSearch(i))
	return true;
    return false;
  }

  int maximumMatching(void) {
    while(findAgumentingPath()) ++matchingSize;
    return matchingSize;
  }
};

int main(){
  int nbcase;
  cin >> nbcase;
  while(nbcase--){
    int n;
    cin >> n;
    
    vector<pi> t(n);
    vector<int> left(n);
    vector<int> right(n);
    for(int i=0;i<n;++i){
      cin >> t[i].first >> t[i].second;
      left[i]=t[i].first;
      right[i]=t[i].second;
    }

    sort(begin(left), end(left));
    left.resize(distance(begin(left),unique(begin(left), end(left))));

    sort(begin(right), end(right));
    right.resize(distance(begin(right),unique(begin(right), end(right))));
    
    map<int, int> to_left;
    for(int i=0;i<int(left.size());++i)
      to_left[left[i]]=i;

    map<int, int> to_right;
    for(int i=0;i<int(right.size());++i)
      to_right[right[i]]=i;

    Bipartite g(left.size(), right.size());
    for(auto p:t)
      g.adjLeft[to_left[p.first]].push_back(to_right[p.second]);

    cout << g.maximumMatching() << '\n';

  }
}
