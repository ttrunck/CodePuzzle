#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int e;
int const N=1<<19;
vector<pair<int,int> > v[N];
int maxi;

void init(){
  for(int i=0;i<N;++i)
    v[i].clear();
  maxi=0;
}

int aux(int k, int from){
  int res=0;
  for(int i=0;i<v[k].size();++i){
    if(from==v[k][i].first) continue;
    res+=max(0, aux(v[k][i].first, k)+v[k][i].second);
  }
  maxi=max(maxi, res);
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin >> e;
  while(e!=0){
    init();
    int a, b, p;
    for(int i=0;i<e;++i){
      cin >> a >> b >> p;
      a--;
      b--;
      v[a].push_back(make_pair(b,p));
      v[b].push_back(make_pair(a,p));
    }
    aux(b,b);
    cout << maxi << endl;
    cin >> e;
  }
}
