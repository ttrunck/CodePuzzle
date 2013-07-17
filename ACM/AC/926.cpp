#include<iostream>
#include<vector>

using namespace std;

typedef long long ent;

int main(){

  int nbcase;
  cin >> nbcase;
  while(nbcase--){
    
    int n;
    cin >> n;
    vector<vector<bool> > h(n, vector<bool>(n, true));
    vector<vector<bool> > v(n, vector<bool>(n, true));

    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    --sx;--sy;--ex;--ey;

    int w;
    cin >> w;
    for(int i=0;i<w;++i){
      int a,b;
      char c;
      cin >> a >> b >> c;
      if(c=='N')
	v[a-1][b-1]=false;
      else if(c=='S')
	v[a-1][b-2]=false;
      else if(c=='E')
	h[a-1][b-1]=false;
      else
    	h[a-2][b-1]=false;
    }

    vector<vector<ent> > t(n, vector<ent>(n,0));
    t[sx][sy]=1;

    for(int i=sx+1;i<=ex;++i)
      if(h[i-1][sy])
	t[i][sy]+=t[i-1][sy];
      
    for(int i=sy+1;i<=ey;++i)
      if(v[sx][i-1])
	t[sx][i]+=t[sx][i-1];      

    for(int i=sx+1;i<=ex;++i)
      for(int j=sy+1;j<=ey;++j){
	if(h[i-1][j])
	  t[i][j]+=t[i-1][j];
	if(v[i][j-1])
	  t[i][j]+=t[i][j-1];
      }
   
    /* 
    for(int i=0;i<n;++i){
      for(int j=0;j<n;++j)
	cerr << v[i][j] << ' ';
      cerr << '\n';
    }

    cerr << '\n';
    
    for(int i=0;i<n;++i){
      for(int j=0;j<n;++j)
	cerr << h[i][j] << ' ';
      cerr << '\n';
    }

    cerr << '\n';

    for(int i=0;i<n;++i){
      for(int j=0;j<n;++j)
	cerr << t[i][j] << ' ';
      cerr << '\n';
    }
    */
    cout << t[ex][ey] << '\n';

  }

}
