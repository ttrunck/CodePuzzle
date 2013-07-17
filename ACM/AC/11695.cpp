#include<iostream>
#include<vector>
#include<set>

using namespace std;

typedef pair<int, int> pi;

void dfs(int s,const vector<set<int> >& t, vector<int>& dist, vector<int>& pred){
  for(set<int>::iterator it=t[s].begin();it!=t[s].end();++it)
    if(dist[*it]==-1){
      dist[*it]=dist[s]+1;
      pred[*it]=s;
      dfs(*it,t,dist,pred);
    }
}

pi diam(int s, const vector<set<int> >& t){
  int n=t.size();
  vector<int> dist(n,-1);
  vector<int> pred(n,-1);

  dist[s]=0;
  dfs(s,t,dist,pred);

  int maxi=-1;
  int x;
  for(int i=0;i<n;++i)
    if(dist[i]>maxi){
      maxi=dist[i];
      x=i;
    }

  dist.assign(n,-1);
  pred.assign(n, -1);
  dist[x]=0;
  dfs(x,t,dist,pred);

  maxi=-1;
  int y;
  for(int i=0;i<n;++i)
    if(dist[i]>maxi){
      maxi=dist[i];
      y=i;
    }
  
  for(int i=0;2*i<maxi;++i,y=pred[y]);

  return pi(maxi,y);
}

int main(){
  int N;
  cin >> N;
  while(N--){
    int n;
    cin >> n;
    vector<set<int> > t(n);
    vector<pi> e;
    for(int i=0;i<n-1;++i){
      int a,b;
      cin >> a >> b;
      --a;--b;
      t[a].insert(b);
      t[b].insert(a);
      e.push_back(pi(a,b));
    }

    int mini=n;
    pi add;
    pi del;

    pi mid=diam(0,t);
    vector<int> vois;
    for(set<int>::iterator it=t[mid.second].begin();it!=t[mid.second].end();++it)
      vois.push_back(*it);

    for(vector<int>::iterator it=vois.begin();it!=vois.end();++it){
 
      t[mid.second].erase(*it);
      t[*it].erase(mid.second);

      pi a=diam(mid.second, t);
      pi b=diam(*it, t);
       
      t[a.second].insert(b.second);
      t[b.second].insert(a.second);
      
      pi f=diam(0, t);
      
      if(f.first<mini){
	mini=f.first;
	del=pi(mid.second, *it);
	add=pi(a.second, b.second);
      }

      t[a.second].erase(b.second);
      t[b.second].erase(a.second);

      t[mid.second].insert(*it);
      t[*it].insert(mid.second);

    }

    cout << mini << '\n';
    cout << del.first+1 << ' ' << del.second+1 << '\n';
    cout << add.first+1 << ' ' << add.second+1 << '\n'; 
  }
}
