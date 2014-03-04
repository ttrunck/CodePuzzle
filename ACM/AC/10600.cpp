#include<iostream>
#include<algorithm>
#include<vector>
#include<limits>

using namespace std;

int n, m;

struct edge{
  int a,b,c;
  edge(int aa=0, int bb=0, int cc=0):a(aa),b(bb),c(cc){}
};

bool operator<(const edge & e, const edge & d){
  return e.c<d.c;
}

int find(int x, vector<int> & p){
  if(p[x]==-1) return x;
  int tmp=find(p[x], p);
  return p[x]=tmp;
}

void fusion(int a, int b, vector<int> & p){
  p[find(a, p)]=find(b, p);
}

int aux(int s, const vector<edge> & t, vector<int> & used, bool r){
  vector<int> p(n+1,-1);
  int c=0;
  int res=0;
  for(int i=0;i<m;++i){
    if(i==s) continue;
    if(c==n-1) break;
    if(find(t[i].a, p)!=find(t[i].b, p)){
      if(r) used.push_back(i);
      c++;
      res+=t[i].c;
      fusion(t[i].a, t[i].b, p);
    }
  }
  
  return (c==n-1)?res:numeric_limits<int>::max();
}

int main(){
  int cas;
  cin >> cas;
  while(cas--){
    cin >> n >> m;
    vector<edge> t(m);
    for(int i=0;i<m;++i)
      cin >> t[i].a >> t[i].b >> t[i].c;
    sort(t.begin(), t.end());
    vector<int> used;
    cout << aux(-1,t,used,true) << ' ';

    int res=numeric_limits<int>::max();
    for(int i=0;i<int(used.size());++i)
      res=min(res, aux(used[i], t, used, false));

    cout << res << '\n';

  }
}
