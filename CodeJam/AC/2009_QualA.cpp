#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>
#include<cassert>

using namespace std;

bool match(const string & s, const string & ss, int L){
  int curr=0;
  for(int i=0;i<L;++i){
    if(s[curr]=='('){
    bool ok=false;
    while(s[curr]!=')'){
      if(s[curr]==ss[i])
	ok=true;
      curr++;
    }
    curr++;
    if(!ok) return false;
    }
    else{
      if(s[curr]!=ss[i]) return false;
      curr++;
    }
  }
    

  return true;
}

void solve(int L, int D, const vector<string> & t){
  int res=0;
  string s;
  cin >> s;
  for(int i=0;i<D;++i)
    if(match(s,t[i],L))
      res++;

  cout << res << '\n';
}

int main(){
  int L,D,N;
  cin >> L >> D >> N;
  vector<string> t(D);
  for(int i=0;i<D;++i)
    cin >> t[i];
  for(int icase=1;icase<=N;++icase){
    cout << "Case #" << icase << ": ";
    solve(L,D,t);
  }
}
