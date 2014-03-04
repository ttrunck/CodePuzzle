#include<iostream>
#include<vector>
#include<string>
#include <sstream>

using namespace std;

int n;


int fill(int i,int j, vector<vector<bool> > & vu, const vector<vector<int> > & t){
  int res=1;
  vu[i][j]=true;
  int x,y;
  
  x=i+1;y=j;
  if(x>=0 && y>=0 && x<n && y<n && !vu[x][y] && t[x][y]==t[i][j])
    res+=fill(x,y,vu,t);
 x=i-1;y=j;
  if(x>=0 && y>=0 && x<n && y<n && !vu[x][y] && t[x][y]==t[i][j])
    res+=fill(x,y,vu,t);
 x=i;y=j-1;
  if(x>=0 && y>=0 && x<n && y<n && !vu[x][y] && t[x][y]==t[i][j])
    res+=fill(x,y,vu,t);
 x=i;y=j+1;
  if(x>=0 && y>=0 && x<n && y<n && !vu[x][y] && t[x][y]==t[i][j])
    res+=fill(x,y,vu,t);

  return res;
}

bool aux(const vector<vector<int> > & t){
  vector<vector<bool> > vu(n,vector<bool>(n,false));
  for(int i=0;i<n;++i)
    for(int j=0;j<n;++j)
      if(!vu[i][j] && fill(i,j,vu,t)!=n)
	return false;

  return true;
}

int main(){
  while(cin >> n && n){
    cin.ignore();
    vector<vector<int> > t(n,vector<int>(n,0));
    for(int i=1;i<n;++i){
      string s;
      getline(cin, s);
      // cerr << s << endl;
      istringstream buff(s);
      int a,b;
      while(buff >> a >> b)
	t[a-1][b-1]=i;
    }
    cout << (aux(t)?"good":"wrong") << '\n';
  }
}
