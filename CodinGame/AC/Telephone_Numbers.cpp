#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

int main(){
  int n;
  cin >> n;
  unordered_set<string> res;
  for(int i=0;i<n;++i){
    string number;
    cin >> number;
    for(int i=1;i<=int(number.size());++i)
      res.insert(number.substr(0,i));
  }
  cout << res.size() << endl;
}
