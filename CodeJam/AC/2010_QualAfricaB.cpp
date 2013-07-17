#include<iostream>
#include<vector>
#include<string>
#include<sstream>

using namespace std;

void solve(){
  string s;
  getline(cin, s);
  stringstream ss(s);
  vector<string> t;
  string tmp;
  while(ss >> tmp)
    t.push_back(tmp);

  for(int i=t.size()-1;i>=0;--i)
    cout << ' ' << t[i];
  cout << '\n';
}

int main(){
  int N;
  cin >> N;
  cin.ignore();
  for(int icase=1;icase<=N;++icase){
    cout << "Case #" << icase << ":";
    solve();
  }
}
