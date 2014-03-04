#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> t;

int main(){
  string tmp;
  while(cin >> tmp)
    t.push_back(tmp);

  sort(t.begin(),t.end());
  int res;
  int paf;
  for(int i=0;i<t.size();++i){
    paf=0;
    for(int j=0;j<t[i].size();++j)
      paf+=t[i][j]-'A'+1;
    res+=paf*(i+1);
  }

  cout << res << '\n';
}
