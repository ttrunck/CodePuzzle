#include<iostream>
#include<vector>

using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  
  vector<vector<int> > t(n, vector<int>(n,0));
  for(int i=0;i<m;++i){
    int a,b,d;
    cin >> a >> b >> d;
    t[a-1][b-1]+=d;
  }
    

  bool conti=true;
  while(conti){
    conti=false;
  for(int i=0;i<n;++i)
    for(int j=0;j<n;++j)
      if(t[i][j]>0)
	for(int k=0;k<n;++k)
	  if(t[i][j]>0 && t[j][k]>0){
	    conti=true;
	    int d=min(t[i][j],t[j][k]);
	    t[i][k]+=d;
	    t[i][j]-=d;
	    t[j][k]-=d;
	  }
  }

  int res=0;
  for(int i=0;i<n;++i)
    for(int j=0;j<n;++j)
      res+=t[i][j];

  cout << res << '\n';
}
