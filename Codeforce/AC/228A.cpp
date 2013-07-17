#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(){
  vector<int> t(4);
  for(int i=0;i<4;++i)
    cin >> t[i];
  sort(t.begin(), t.end());
  t.resize(unique(t.begin(),t.end())-t.begin());
  cout << 4-t.size() << '\n';
}
