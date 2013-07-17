#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

const int N=10009;
const int C=20;
vector<int> t[N];
int col[N][20];
bool root[N];

int color(int start, int c){
  if(col[start][c]!=0) return col[start][c];
  
  int res=c;
  for(int i=0;i<t[start].size();++i){
    int tmp=N*N;
    for(int co=1;co<C;++co){
      if(co==c) continue;
      tmp=min(tmp, color(t[start][i], co));
    }
    res+=tmp;
  }
  col[start][c]=res;
  return res;
}

int main(){
  int n;
  cin >> n;
  string line;
  getline(cin, line);
  while(n!=0){
    for(int i=0;i<n;++i){
      t[i].clear();
      root[i]=true;
    }
    for(int i=0;i<N;++i)
      for(int j=0;j<C;++j)
	col[i][j]=0;

    for(int i=0;i<n;++i){
      getline(cin, line);
      istringstream iss;
      iss.str(line);
      int k;
      char tmp;
      iss >> k >> tmp;
      while(iss >> k){
	t[i].push_back(k);
	root[k]=false;
      }
    }
    
    int ro=-1;
    for(int i=0;i<n;++i)
      if(root[i]) ro=i;

    int res=N*N;
    for(int i=1;i<C;++i)
      res=min(res, color(ro,i));
    cout << res << endl;
    
    cin >> n;
    getline(cin, line);
  }
}
