#include<iostream>
#include<vector>
#include<utility>
#include<limits>

using namespace std;

int w;
vector<pair<int,int> > tab;
vector<vector<int> > mem;

int aux(int n, int t){
  if(t<0) return numeric_limits<int>::min();
  if(n==-1 || t==0) return 0;
  if(mem[n][t]!=-1) return mem[n][t];
  int tmp=max(aux(n-1,t),aux(n-1,t-3*w*tab[n].first)+tab[n].second);
  mem[n][t]=tmp;
  return tmp;
}

int main(){
  bool first=true;
  int t;
  while(cin >> t >> w){
    int n;
    cin >> n;
    mem=vector<vector<int> >(n, vector<int>(t+1,-1));
    tab=vector<pair<int,int> >(n);
    for(int i=0;i<n;++i)
      cin >> tab[i].first >> tab[i].second;
    int val=aux(n-1,t);

    if(first)
      first=false;
    else
      cout << endl;

    cout << val << endl;

    vector<pair<int,int> > res;
    for(int i=n-1;i>=0;--i){
      //   cout << "pif " << aux(i-1,t-3*w*tab[i].first)+tab[i].second << ' ' << val << endl;
      if(aux(i-1,t-3*w*tab[i].first)+tab[i].second==val){
	val-=tab[i].second;
	t-=3*w*tab[i].first;
	res.push_back(tab[i]);
      }
    }
    cout << res.size() << endl;
    for(int i=int(res.size())-1;i>=0;--i)
      cout << res[i].first << ' ' << res[i].second << endl;
    
  }
}
