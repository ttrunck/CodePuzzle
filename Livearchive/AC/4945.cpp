#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> pi;

bool mysort(const pi& a, const pi& b){
  return (a.first < b.first) || (a.first==b.first && a.second>b.second);
}

pi mymax(const pi& a, const pi& b){
  if ((a.second < b.second) || (a.second==b.second && a.first<b.first))
    return b;
  else
    return a;
				
}

pi operator+(const pi& a, const pi& b){
  return pi(a.first+b.first, a.second+b.second);
}

int par;

pi aux(int n, int k, const vector<pi>& t, vector<vector<pi> >& mem){

  if(n+1==k){
    pi res=pi(0,0);
    for(int i=0;i<=n;++i)
      res.second+=t[i].second;
    return res;
  }

  if(k==0){
    pi res=pi(0,0);
    for(int i=0;i<=n;++i)
      res.first+=t[i].first;
    return res;
  }
 

   if(mem[n][k].first!=-1) return mem[n][k];
  
   pi res=mymax((n+1+par==2*k)?(aux(n-2, k-1, t, mem)+pi(t[n-1].first, t[n].second)):aux(n-1, k-1, t, mem)+pi(0, t[n].second),
	       aux(n-1, k, t, mem)+pi(t[n].first, 0));
   
  return mem[n][k]=res;
}

int main(){

  int nbcase;
  cin >> nbcase;
  while(nbcase--){
    int n;
    string start;
    cin >> n >> start;

    vector<pi> t(n);
    for(int i=0;i<n;++i)
      cin >> t[i].first >> t[i].second;

    sort(t.begin(), t.end(), mysort);

    vector<vector<pi> > mem(n, vector<pi>(n, pi(-1, -1)));
    
    pi res=pi(0, 0);
    if(start=="Petra"){
      res.first+=t.back().first;
      t.pop_back();
      n--;
    }

    par=n%2;

    res = res + aux(n-1, (n+1)/2, t, mem);
    cout << res.first << ' ' << res.second << '\n';
  }
}
