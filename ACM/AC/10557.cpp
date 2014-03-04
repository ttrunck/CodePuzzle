#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;


vector<int> energ;
vector<vector<int> > v;
vector<int> value;
const int MINI=-1000000;
vector<bool> visit;

bool dfs(int s, int f){
  if(s==f) return true;
  visit[s]=true;
  bool res=false;
  for(int i=0;i<v[s].size();++i)
    if(!visit[v[s][i]])
      res=res||dfs(v[s][i], f);
  return res;
}

int bellman(int s, int f){
  for(int i=0;i<value.size();++i)
    value[s]=-MINI;
  
  value[s]=100;
  
  for(int cas=0;cas<v.size();++cas)
    for(int i=0;i<v.size();++i)
      for(int j=0;j<v[i].size();++j){
	if(value[i]>0)
	  value[v[i][j]]=max(value[v[i][j]], value[i]+energ[v[i][j]]);
      }

  for(int i=0;i<v.size();++i)
      for(int j=0;j<v[i].size();++j){
	if(value[i]>0)
	  if(value[v[i][j]] < value[i]+energ[v[i][j]]){
	    for(int k=0;k<value.size();++k)
	      visit.push_back(false);
	    if(dfs(v[i][j], f)) return 100;
	  }
      }
  
  return value[f];
}

int main(){
  int n;
  cin >> n;
    while(n!=-1){
      energ.clear();
      v.clear();
      value.clear();
      visit.clear();
      
      for(int i=0;i<n;++i){
	int tmp;
	vector<int> t;
	cin >> tmp;
	energ.push_back(tmp);
	value.push_back(MINI);
	int nb;
	cin >> nb;
	for(int j=0;j<nb;++j){
	  cin >> tmp;
	  t.push_back(tmp-1);
	}
	v.push_back(t);
      }

      //  cout << bellman(0, n-1) << endl;
      if(bellman(0,n-1)>0)
	cout << "winnable" << endl;
      else
	cout << "hopeless" << endl;

      cin >> n;
    }
}
