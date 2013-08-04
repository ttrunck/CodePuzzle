#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

void add(string& s, const string& t){
  if(s.find(t)!=string::npos)
    return;

  for(int i=min(s.size(), t.size());i>=0;--i)
    if(s.substr(s.size()-i)==t.substr(0,i)){
      s+=t.substr(i);
      return;
    }
}

int solve(const vector<string>& t){
  string s_tot;
  for(auto s:t){
    add(s_tot,s);
  }
  return s_tot.size();
}

int main(){
  int n;
  cin >> n;
  int res=0;
  vector<string> t(n);
  for(int i=0;i<n;++i){
    cin >> t[i];
    res+=t[i].size();
  }
  sort(begin(t), end(t));
  do{
    res=min(res, solve(t));
  }while(next_permutation(begin(t), end(t)));
  cout << res << '\n'; 
}
