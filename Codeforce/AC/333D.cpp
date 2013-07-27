#include<iostream>
#include<vector>

using namespace std;

int n,m;

bool ok(int val, const vector<vector<int> >& t){

  vector<vector<bool> > tok(m,vector<bool>(m,false));
  for(int i=0;i<n;++i){
    vector<int> okj;
    for(int j=0;j<m;++j)
      if(t[i][j]>=val)
	okj.push_back(j);
    for(int m1=0;m1<int(okj.size());++m1)
      for(int m2=m1+1;m2<int(okj.size());++m2){
	if(tok[okj[m1]][okj[m2]]) return true;
	tok[okj[m1]][okj[m2]]=true;
      }
  }
  return false;
}

int main(){
  ios::sync_with_stdio(false);
  cin >> n >> m;
  vector<vector<int> >  t(n, vector<int>(m));
  for(int i=0;i<n;++i)
    for(int j=0;j<m;++j)
      cin >> t[i][j];

  int lo=0,hi=1000000009;
  while(lo!=hi){
    int x=(lo+hi)/2;
    if(ok(x,t))
      lo=x+1;
    else
      hi=x;
  }
  cout << lo-1 << '\n';
}
