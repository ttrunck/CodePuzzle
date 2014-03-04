#include<iostream>
#include<vector>

using namespace std;

int aux(const vector<int> & tab, vector<vector<vector<int> > > & mem, int t, int m, int curr, int n){
  if(n==-1) return 0;

  if(mem[m][curr][n]!=-1) return mem[m][curr][n];

  int res=aux(tab, mem, t, m, curr, n-1);
  if(tab[n]<=curr)
    res=max(res, aux(tab, mem, t, m, curr-tab[n], n-1)+1);
  else if(m>0 && tab[n]<=t)
    res=max(res, aux(tab, mem, t, m-1, t-tab[n], n-1)+1);
  
  return mem[m][curr][n]=res;
}

int main(){
  bool first=true;
  int cas;
  cin >> cas;
  while(cas--){
    int n, t, m;
    cin >> n >> t >> m;
    vector<int> tab(n);
    cin >> tab[0];
    char c;
    for(int i=1;i<n;++i)
      cin >> c >> tab[i];
  
    vector<vector<vector<int> > > mem(m, vector<vector<int> >(t+1, vector<int>(n,-1)));

    if(!first)
      cout << '\n';
    first=false;
    cout << aux(tab, mem, t, m-1, t, n-1) << '\n';
  }
}
