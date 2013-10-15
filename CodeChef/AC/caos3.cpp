#include<iostream>
#include<vector>
#include<set>

using namespace std;

const vector<pair<int, int> > dir{{0,1}, {0,-1}, {1,0}, {-1,0}};

int win(int, int, int, int, const vector<vector<bool> >&, vector<vector<vector<vector<int> > > >&, vector<vector<vector<vector<int> > > >&);

bool ok(int x, int y, const vector<vector<char> >& t){
  for(auto d:dir){
    for(int i=1;i<=2;++i){
      if(t[x+d.first*i][y+d.second*i]=='#')
	return false;
    }
  }
  return true;
}

int win(int x1, int x2, int y1, int y2, const vector<vector<bool> >& t, vector<vector<vector<vector<int> > > >& mem_win){

  if(x1>=int(t.size()) || y1>=int(t[0].size()))
    return 0;

  if(mem_win[x1][x2][y1][y2]!=-1) return mem_win[x1][x2][y1][y2];

  set<int> s;
  int res = 0;
  for(int i=x1;i<x2;++i)
    for(int j=y1;j<y2;++j)
      if(t[i][j]){
	int tmp=win(x1,i,y1,j,t,mem_win) ^ win(i+1,x2,y1,j,t,mem_win) ^ win(x1,i,j+1,y2,t,mem_win) ^ win(i+1,x2,j+1,y2,t,mem_win);
	if(tmp>=0)
	  s.insert(tmp);
      }
  
  while(s.find(res) != end(s)) ++res;
  return mem_win[x1][x2][y1][y2]=res;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int r, c;
    cin >> r >> c;
    vector<vector<char> > tt(r, vector<char>(c));
    vector<vector<bool> > t(r, vector<bool>(c, false));
     
    
    for(int i=0;i<r;++i)
      for(int j=0;j<c;++j)
	cin >> tt[i][j];

    for(int i=2;i<r-2;++i)
      for(int j=2;j<c-2;++j)
	if(tt[i][j]=='^' && ok(i,j,tt))
	  t[i][j]=true;
      
    vector<vector<vector<vector<int> > > > mem_win(r, vector<vector<vector<int> > >(r+1, vector<vector<int> >(c, vector<int>(c+1,-1))));

    if(win(0,r,0,c,t, mem_win)!=0)
      cout << "Asuna\n";
    else
      cout << "Kirito\n";
	

  }
}
