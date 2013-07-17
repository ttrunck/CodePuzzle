#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>

using namespace std;

long long convert(const vector<int>& t, int base){
  long long res=0;
  for(int i=0;i<int(t.size());++i)
    res=res*base+t[i];
  return res;
}

void solve(){
  string s;
  cin >> s;
  vector<int> t(s.size());
  map<char, int> m;
  int curr = 0;
  m[s[0]]=1;
  t[0]=1;
  for(int i=1;i<int(s.size());++i){
    if(m.find(s[i])==m.end()){
      m[s[i]]=curr;
      curr++;
      if(curr==1)
	curr++;
    }
    t[i]=m.find(s[i])->second;
  }

  //cerr << endl << "FIN CURR " << curr << endl;

  cout << convert(t, max(2,curr)) << '\n';
}

int main(){
  int N;
  cin >> N;
  cin.ignore();
  for(int icase=1;icase<=N;++icase){
    cout << "Case #" << icase << ": ";
    solve();
  }
}
