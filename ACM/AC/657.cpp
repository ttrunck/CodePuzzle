#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<cassert>

using namespace std;

int n,m;

void f(int i, int j, const vector<vector<char> > & t, vector<vector<bool> > & vu, stack<pair<int,int> > & s){
    if(i>=0 && j>=0 && i<n && j<m && !vu[i][j] && t[i][j]=='X'){
      vu[i][j]=true;
      s.push(make_pair(i,j));
    }
}

void fill(int x, int y, const vector<vector<char> > & t, vector<vector<bool> > & vu){
  stack<pair<int, int> > s;
  s.push(make_pair(x,y));
  vu[x][y]=true;
  while(!s.empty()){
    int i=s.top().first, j=s.top().second;
    s.pop();
    f(i+1,j,t,vu,s);
    f(i-1,j,t,vu,s);
    f(i,j+1,t,vu,s);
    f(i,j-1,t,vu,s);
  }
}

void g(int i, int j, const vector<vector<char> > & t, vector<vector<bool> > & vu, stack<pair<int,int> > & s){
    if(i>=0 && j>=0 && i<n && j<m && !vu[i][j] && t[i][j]!='.')
      s.push(make_pair(i,j));
}

void aux(const vector<vector<char> > & t, vector<int> & res){
  vector<vector<bool> > vu(n, vector<bool>(m,false));
  
  for(int i=0;i<n;++i)
    for(int j=0;j<m;++j){
      if(vu[i][j]) continue;
      if(t[i][j]=='.'){
	vu[i][j]=true;
	continue;
      }
      //  cerr << i << ' ' << j << ' ' << t[i][j];
      assert(t[i][j]=='*');
      int tmp=0;
      stack<pair<int, int> > s;
      s.push(make_pair(i,j));
      while(!s.empty()){
	int i=s.top().first, j=s.top().second;
	s.pop();
	if(vu[i][j]) continue;
	if(t[i][j]=='X'){
	  fill(i,j,t,vu);
	  tmp++;
	}
	vu[i][j]=true;
	g(i+1,j,t,vu,s);
	g(i-1,j,t,vu,s);
	g(i,j+1,t,vu,s);
	g(i,j-1,t,vu,s);
      }
      res.push_back(tmp);
    }
 }

int main(){
  int icas=1;
  while(cin >> m >> n && (n||m)){
    cout << "Throw " << icas++ << '\n';
    vector<vector<char> > t(n,vector<char>(m));
    for(int i=0;i<n;++i)
      for(int j=0;j<m;++j)
	cin >> t[i][j];
    vector<int> res;
    aux(t,res);
    sort(res.begin(), res.end());
    cout << res[0];
    for(int i=1;i<int(res.size());++i)
      cout << ' ' << res[i];
    cout << "\n\n";
  }
}
