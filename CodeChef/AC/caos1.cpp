#include<iostream>
#include<vector>

using namespace std;

const vector<pair<int, int> > dir{{0,1}, {0,-1}, {1,0}, {-1,0}};

bool ok(int x, int y, const vector<vector<char> >& t){
  for(auto d:dir){
    for(int i=1;i<=2;++i){
      if(t[x+d.first*i][y+d.second*i]=='#')
	return false;
    }
  }
  return true;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int r, c;
    cin >> r >> c;
    vector<vector<char> > t(r, vector<char>(c));
    for(int i=0;i<r;++i)
      for(int j=0;j<c;++j)
	cin >> t[i][j];

    int res=0;
    for(int i=2;i<r-2;++i)
      for(int j=2;j<c-2;++j)
	if(t[i][j]=='^' && ok(i,j,t))
	  res++;

    cout << res << '\n';
  }
}
