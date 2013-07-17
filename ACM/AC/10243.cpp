#include<iostream>
#include<vector>
#include<cmath>
#include<limits>

using namespace std;

const int N=1009;
vector<bool> see; 

/*
int aux(int parent, bool couvert, int node, bool exit, const vector<vector<int> > & t, vector<vector<int> > & mem){
  see[node]=true;

  //  cerr << parent << ' ' << node << ' ' << exit << endl;

  if(couvert && int(t[node].size())==1) return 0; 

  if(mem[node][exit]!=-1) return mem[node][exit];
  int res=numeric_limits<int>::max();

  int tmp=1;
  if(exit){
    for(int i=0;i<int(t[node].size());++i){
      if(t[node][i]==parent) continue;
      tmp+=min(aux(node, true, t[node][i], true, t, mem), aux(node,true , t[node][i], false, t, mem));
    }
    mem[node][exit]=tmp;
    return tmp;
  }

  for(int i=0;i<int(t[node].size());++i){
    if(t[node][i]==parent) continue;
    tmp=0;
    for(int j=0;j<int(t[node].size());++j){
      if(t[node][j]==parent) continue;
      if(i==j)
	tmp+=aux(node, false, t[node][j], true, t, mem);
      else
	tmp+=min(aux(node, false , t[node][j], true, t, mem), aux(node, false, t[node][j], false, t, mem));
    }
    res=min(res, tmp);
  }

  mem[node][exit]=res;
  return res;
}
*/

int aux(int parent, int node, int exit, const vector<vector<int> > & t, vector<vector<int> > & m){
  see[node]=true;
  if(m[node][exit]!=-1) return m[node][exit];
  int res=0;
  
  if(!exit){
    if(int(t[node].size())==0) return int(see.size())*10;
    for(int i=0;i<int(t[node].size());++i){
      if(t[node][i]==parent) continue;
      res+=aux(node,t[node][i],true,t,m);
    }
  }
  else{
    for(int i=0;i<int(t[node].size());++i){
      if(t[node][i]==parent) continue;
      res+=min(aux(node,t[node][i],true,t,m), aux(node,t[node][i], false, t, m));
    }
    res++;
  }

  m[node][exit]=res;
  return res;
}

int main(){
  int n;
  cin >> n;
  while(n!=0){
    vector<vector<int> > t;
    vector<vector<int> > mem(n, vector<int>(2,-1));
    for(int i=0;i<n;++i){
      int nb;
      cin >> nb;
      t.push_back(vector<int>(nb));
      for(int j=0;j<nb;++j){
	cin >> t[i][j];
	t[i][j]--;
      }
    }
    see=vector<bool>(n,false);
    int res=0;
    for(int i=0;i<n;++i)
      if(!see[i])
	//	res+=min(aux(i, false, i,true, t, mem), aux(i, false, i,false, t, mem));
	res+=min(aux(i,i,true,t,mem), aux(i,i,false,t,mem));

    cout << res << endl;
    cin >> n;
  }
}
