#include<iostream>
#include<vector>

using namespace std;

int main(){
  int k;
  cin >> k;
  vector<int> t(10,0);
  for(int i=0;i<16;++i){
    char tmp;
    cin >> tmp;
    if(tmp!='.')
      ++t[tmp-'0'];
  }
  
  for(int x:t)
    if(x>2*k){
      cout << "NO\n";
      return false;
    }

  cout << "YES\n";
}
