#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

struct edge{
  int a,b,c;
  edge(int aa=0,int bb=0, int cc=0):a(aa), b(bb), c(cc){}
};

bool operator<(edge e, edge d){
  return e.c < d.c;
}

int find(int x, vector<int> & p){
  if(p[x]==-1) return x;
  return p[x]=find(p[x], p);
}

void fusion(int a, int b, vector<int> & p){
  p[find(a,p)]=find(b,p);
}

int main(){
  int n, m;
  while(cin >> n >> m && (n!=0 || m!=0)){
    set<int> edges;
    vector<edge> t(m);
    for(int i=0;i<m;++i){
      cin >> t[i].a >> t[i].b >> t[i].c;
      edges.insert(t[i].c);
    }
    sort(t.begin(), t.end());
    vector<int> p(n,-1);

    for(int i=0;i<m;++i){
      if(find(t[i].a,p)!=find(t[i].b,p)){
	edges.erase(t[i].c);
	fusion(t[i].a, t[i].b, p);
      }
    }

    if(edges.empty()) cout << "forest\n";
    else{
      set<int>::iterator it=edges.begin();
      cout << *it;
      it++;
      for(;it!=edges.end();++it)
	cout << ' ' << *it;
      cout << '\n';
    }
  }
}
