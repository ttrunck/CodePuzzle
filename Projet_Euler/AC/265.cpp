#include<iostream>
#include<set>
#include<vector>

typedef long long ll;

using namespace std;

const int N=5;

ll res=0;

void aux(int pos, vector<int>& t, set<int>& s){
  if(int(s.size())==(1<<N)){
    cerr << "OK\n";
    for(int x:t)
      cerr << x;
    cerr << '\n';

    ll tmp=0;
    for(int x:t){
      tmp*=2;
      tmp+=x;
      }
    cerr << tmp << endl;
    res+=tmp;
  }

  int nb=0;
  for(int i=pos-N+1;i<pos;++i){
    nb+=t[i];
    nb*=2;
  }

  if(s.find(nb)==end(s)){
    s.insert(nb);
    aux(pos+1, t, s);
    s.erase(nb);
  }

  if(s.find(nb+1)==end(s)){
    t[pos]=1;
    s.insert(nb+1);
    aux(pos+1, t, s);
    s.erase(nb+1);
    t[pos]=0;
  }

}

int main(){

  vector<int> t(1<<N,0);
  set<int> s;
  s.insert(0);

  aux(N, t, s);

  cout << res << '\n';
}
