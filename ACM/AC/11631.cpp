#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct edge{
  int a,b,c;
  edge(int aa=0, int bb=0, int cc=0):a(aa),b(bb),c(cc){}
};

bool operator<(const edge & e, const edge & d){
  return e.c < d.c;
}

int find(int x, vector<int> & p){
  if(p[x]==-1) return x;
  int tmp=find(p[x], p);
  return p[x]=tmp;
}

void fusion(int a, int b, vector<int> & p){
  p[find(a, p)]=find(b, p);
}

int main(){
  int n, m;
  cin >> n >> m;
  while((n!=0 || m!=0)){
    vector<edge> t(m);
    int costmax=0;
    for(int i=0;i<m;++i){
      cin >> t[i].a >> t[i].b >> t[i].c;
      costmax+=t[i].c;
    }
    sort(t.begin(), t.end());

    int c=0, cost=0;
    vector<int> p(n,-1);

    for(int i=0;i<m;++i){
      if(c==n-1) break;
      if(find(t[i].a,p)!=find(t[i].b,p)){
	c++;
	cost+=t[i].c;
	fusion(t[i].a, t[i].b, p);
      }
    }
      cout << costmax-cost << '\n';
      cin >> n >> m;
  }
}
