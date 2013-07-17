#include<iostream>
#include<vector>

using namespace std;

typedef pair<int, int> pi;

void longest(int s, const vector<vector<int> >& t, vector<pi>& mem){
  //cerr << s << endl;
 if(mem[s].first!=-1) return;

  int finish=s;
  int size=0;

  for(int i=0;i<int(t[s].size());++i){
    longest(t[s][i],t,mem);
    if(mem[t[s][i]].first+1>size || (mem[t[s][i]].first+1==size && finish>mem[t[s][i]].second)){
      size=mem[t[s][i]].first+1;
      finish=mem[t[s][i]].second;
    }
  }
  
  mem[s]=pi(size, finish);

}

int main(){
  int icase=0;

  int n, s;
  while(cin >> n >> s && n){
    vector<vector<int> > t(n);
    int p,q;
    while(cin >> p >> q && (p!=0||q!=0))
      t[p-1].push_back(q-1);

    vector<pi> mem(n, pi(-1,-1));

    longest(s-1, t, mem);

    /*
    for(auto it:mem)
      cerr << it.first << ' ' << it.second << endl;
    */

    cout << "Case " << ++icase << ": The longest path from " << s << " has length " << mem[s-1].first << ", finishing at " << mem[s-1].second+1 << ".\n\n";

  }
}
