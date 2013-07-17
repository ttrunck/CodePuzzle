#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<limits>

using namespace std;

typedef pair<int, int> pi;

const int INF=numeric_limits<int>::max();

bool solve(const vector<pi>& t, int D){
  int n=t.size();
  vector<int> dist(t.size(),INF);
  dist[0]=0;
  queue<int> q;
  q.push(0);
  while(!q.empty()){
    int curr=q.front();
    q.pop();
    if(2*t[curr].first-dist[curr]>=D)
      return true;
    for(int i=curr+1;i<n;++i)
      if((2*t[curr].first-dist[curr]>=t[i].first)&&(dist[i]>max(t[curr].first, t[i].first-t[i].second))){
	q.push(i);
	dist[i]=max(t[curr].first, t[i].first-t[i].second);
      }
  }
  return false;
}

int main(){
  int nbcase;
  cin >> nbcase;
  for(int icase=1;icase<=nbcase;++icase){
    cout << "Case #" << icase << ": ";
    int n;
    cin >> n;
    vector<pi> t(n);
    for(int i=0;i<n;++i)
      cin >> t[i].first >> t[i].second;
    int D;
    cin >> D;

    if(solve(t, D))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
