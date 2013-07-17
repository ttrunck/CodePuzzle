#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool in (const vector<int>& a, const vector<int>& b){
  for(int i=0;i<int(a.size());++i)
    if(a[i]>=b[i])
      return false;
  return true;
}

bool neq (const vector<int>& a, const vector<int>& b){
  for(int i=0;i<int(a.size());++i)
    if(a[i]!=b[i])
      return true;
  return false;
}

int calc(int x, const vector<vector<int> >& g, vector<vector<int> >& mem){

  if(!mem[x].empty()) return mem[x].size();
  
  int res=-1;
  int maxi=0;
  for(int i=0;i<int(g[x].size());++i){
    if(calc(g[x][i], g, mem)>maxi){
      maxi=mem[g[x][i]].size();
      res=g[x][i];
    }
  }

  mem[x].push_back(x);
  if(res!=-1){
    for(int i=0;i<int(mem[res].size());++i)
      mem[x].push_back(mem[res][i]);
  }

    return mem[x].size();
}

int main(){
  int n,d;
  while(cin >> n >> d){
    vector<vector<int> > t(n, vector<int>(d));
    for(int i=0;i<n;++i){
      for(int j=0;j<d;++j)
	cin >> t[i][j];
      sort(t[i].begin(), t[i].end());
    }

    vector<vector<int> > g(n);
    for(int i=0;i<n;++i)
      for(int j=0;j<n;++j)
	if(i!=j && in(t[i], t[j]) && (neq(t[i], t[j]) || i<j))
	  g[i].push_back(j);
      
    int res=-1;
    int maxi=0;
    vector<vector<int> > mem(n);
    for(int i=0;i<n;++i)
      if(calc(i, g, mem)>maxi){
	maxi=mem[i].size();
	res=i;
      }


    cout << mem[res].size() << '\n' << mem[res][0]+1;
    for(int i=1;i<int(mem[res].size());++i)
      cout << ' ' << mem[res][i]+1;
    cout << '\n';
      

  }
}
