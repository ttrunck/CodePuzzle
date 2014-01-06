#include<iostream>
#include<vector>

using namespace std;

typedef pair<int, int> pi;

bool aux(int s, const vector<vector<pi> >& t, vector<bool>& visited, vector<int>& res){
  visited[s]=true;
  bool ok=false;

  for(const pi& p:t[s]){
    if(visited[p.first]) continue;
    bool done=aux(p.first, t, visited, res);
    ok=ok||done;
    if(!done && p.second==2){
      res.push_back(p.first);
      ok=true;
    }
  }
  return ok;
}

int main(){
  int n;
  cin >> n;
  vector<vector<pi> > t(n);
  for(int i=0;i<n-1;++i){
    int a,b,c;
    cin >> a >> b >> c;
    t[a-1].push_back(pi{b-1,c});
    t[b-1].push_back(pi{a-1,c});
  }
  
  vector<bool> visited(n,false);
  vector<int> res;

  aux(0, t, visited, res);
  
  cout << res.size() << '\n';
  for(int i=0;i<int(res.size());++i)
    cout << res[i]+1 << ' ';
}
