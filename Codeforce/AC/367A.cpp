#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){

  string s;
  cin >> s;
  int m=int(s.size());

  vector<int> x(m+1,0);
  for(int i=0;i<m;++i)
    x[i+1]=x[i]+(s[i]=='x'?1:0);

  vector<int> y(m+1,0);
  for(int i=0;i<m;++i)
    y[i+1]=y[i]+(s[i]=='y'?1:0);

  vector<int> z(m+1,0);
  for(int i=0;i<m;++i)
    z[i+1]=z[i]+(s[i]=='z'?1:0);

  int n;
  cin >> n;
  for(int i=0;i<n;++i){
    int l, r;
    cin >> l >> r;
    if(r-l+1<3)
      cout << "YES\n";
    else{
      int nbx=x[r]-x[l-1];
      int nby=y[r]-y[l-1];
      int nbz=z[r]-z[l-1];

      if(nbx<nby) swap(nbx, nby);
      if(nbx<nbz) swap(nbx, nbz);
      if(nby<nbz) swap(nby, nbz);

      //cerr << nbx << ' ' << nby << ' ' << nbz << '\n';

      if(nbx>nbz+1)
	cout << "NO\n";
      else
	cout << "YES\n";

    }
  }
}
