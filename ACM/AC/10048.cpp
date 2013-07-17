#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct edge{
  int a,b,w;
  edge(int aa=0, int bb=0, int ww=0):a(aa),b(bb),w(ww) {};
  bool operator<(const edge & e) const{
    return w<e.w;
  }
};

int find(int s, vector<int>& pere){
  if(pere[s]==s) return s;
  int res=find(pere[s], pere);
  return pere[s]=res;
}

int solve(int s, int e, const vector<edge>& t, vector<int>& pere){
  for(unsigned int i=0;i<t.size();++i){
    pere[find(t[i].a,pere)]=find(t[i].b,pere);
    if(find(s,pere)==find(e,pere))
      return t[i].w;
  }

  return -1;
}

int main(){
  int C, S, Q;
  int icase=1;
  while(cin >> C >> S >> Q && (C||S||Q)){
    if(icase!=1)
      cout << '\n';
    cout << "Case #" << icase++ << '\n';
    vector<edge> t(S);
    for(int i=0;i<S;++i)
      cin >> t[i].a >> t[i].b >> t[i].w;
    sort(t.begin(), t.end());

    for(int i=0;i<Q;++i){
      vector<int> pere(C+1);
      for(int i=0;i<C+1;++i)
	pere[i]=i;
      int s, e;
      cin >> s >> e;
      int res=solve(s,e,t,pere);
      if(res==-1)
	cout << "no path\n";
      else
	cout << res << '\n';
    }
    
  }
}
