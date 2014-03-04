#include<iostream>
#include<vector>
#include<utility>
#include<cmath>

using namespace std;

typedef pair<int,int> habit;
vector<habit> h;

pair<int,int> t[101][10001];

int m,n;
bool credit;

void init(){
  for(int i=0;i<101;++i)
    for(int j=0;j<10001;++j)
      t[i][j]=make_pair(-1,-1);
}

pair<int,int> aux(int d, int arg){
  if(arg<=0) return make_pair(0,0);

  if(d>=n && arg==0) return make_pair(0,0);
  if(d>=n) return make_pair(0,-100000000);
  if(t[d][arg].second!=-1) return t[d][arg];
  pair<int,int> res=aux(d+1, arg);;
  if(arg>= h[d].first){
    pair<int,int> tmp=aux(d+1,arg-h[d].first);
    tmp.second+=h[d].second;
    tmp.first+=h[d].first;
    if(tmp.second>res.second)
      res=tmp;
  }
  t[d][arg]=res;
  return res;
}

int main(){
  while(cin >> m >> n){
    int p, f;
    h.clear();
    init();
    for(int i=0;i<n;++i){
      cin >> p >> f;
      h.push_back(make_pair(p,f));
    }
    pair<int,int> cred=aux(0,m);
    int res=cred.second;
    for(int i=0;i<=m+200;++i){
      cred=aux(0,i);
      if( (i<=m || cred.first>2000) && cred.second>res)
	res=cred.second;
    }
    cout << res << endl;
  }
}
