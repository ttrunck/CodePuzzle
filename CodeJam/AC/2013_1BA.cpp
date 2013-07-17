#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

int aux(int a, int pos, const vector<int> & t, map<pair<int, int>, int> & mem){
  // cerr << a << ' ' << pos << endl;
  if(pos==int(t.size())) return 0;
  pair<int, int> paire(a,pos);
  auto it=mem.find(paire);
  if(it!=mem.end()) return it->second;
  int res=int(t.size());
  if(a>t[pos])
    res=aux(a+t[pos],pos+1,t,mem);
  else{
    if(a>1){
      int aa=a, tmp=0;
      while(aa<=t[pos]){
	tmp++;
	aa+=aa-1;
      }
      aa+=t[pos];
      res=tmp+aux(aa,pos+1,t,mem);
    }
    res=min(res, 1+aux(a,pos+1,t,mem));
  }
  mem[paire]=res;
  return res;
}

int main(){
  int nbcase;
  cin >> nbcase;
  for(int icase=1;icase<=nbcase;++icase){
    cout << "Case #" << icase << ": ";
    int A, N;
    cin >> A >> N;
    vector<int> t(N);
    for(int i=0;i<N;++i)
      cin >> t[i];
    sort(t.begin(), t.end());
    map<pair<int, int>, int> mem;
    cout << aux(A,0,t,mem) << '\n';

  }
}
