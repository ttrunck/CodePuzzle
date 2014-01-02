#include<iostream>
#include<vector>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> t(n);
  for(int i=0;i<n;++i)
    cin >> t[i];

  while(t[0]){
    cout << "PRL";
    t[0]--;
  }
  int pos=1;
  while(pos<n){
    cout << "R";
    while(t[pos]){
      cout << "PLR";
      t[pos]--;
    }
    ++pos;
  }
  cout << '\n';
}
