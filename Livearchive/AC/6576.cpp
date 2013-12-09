#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>

using namespace std;

bool backtrack(const vector<vector<int> >& t, vector<int>& color, vector<vector<int> >& neigh){

  int n=int(t.size());

  int v=-1;
  int maxi=-1;
  for(int i=0;i<n;++i)
    if(color[i]==0){
      int cont=0;
      for(int j=0;j<4;++j)
	if(neigh[i][j]!=0)
	  cont++;
      if(cont>maxi){
	maxi=cont;
	v=i;
      }
    }

  if(v==-1)
    return true;
  
  for(int i=1;i<=4;++i)
    if(neigh[v][i-1]==0){
      
      color[v]=i;
      for(int j=0;j<int(t[v].size());++j)
	neigh[t[v][j]][i-1]++;

      if(backtrack(t,color,neigh))
	return true;

      color[v]=0;
      for(int j=0;j<int(t[v].size());++j)
	neigh[t[v][j]][i-1]--;
    }
  return false;
}

int main(){
  int N;
  bool first=true;
  while(cin >> N){
    if(!first)
      cout << '\n';
    first=false;

  vector<vector<int> > t(N);
  vector<vector<int> > v(N, vector<int>(4,0));
  vector<int> color(N);

  cin.ignore();
  int a,b;
  char c;
  string s;
  while(getline(cin, s)){
    if(s.size()<1) break;
    istringstream ss(s);
    ss >> a >> c >> b;
    t[a-1].push_back(b-1);
    t[b-1].push_back(a-1);
  }

  for(int i=0;i<N;++i){
    sort(t[i].begin(), t[i].end());
    t[i].resize( distance(t[i].begin(),unique (t[i].begin(), t[i].end())) ); 
  }

  backtrack(t,color,v);

  for(int i=0;i<N;++i)
    cout << i+1 << ' ' << color[i] << '\n';
  }
}
