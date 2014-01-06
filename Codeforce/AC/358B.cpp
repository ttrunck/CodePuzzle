#include<iostream>
#include<string>

using namespace std;

int main(){
  int n;
  cin >> n;
  string s;
  for(int i=0;i<n;++i){
    string tmp;
    cin >> tmp;
    s+="<3";
    s+=tmp;
  }
  s+="<3";
  string ss;
  cin >> ss;

  int is=0, iss=0;
  
  while(is<int(s.size())){
    while(iss<int(ss.size()) && ss[iss]!=s[is])++iss;
    if(iss==int(ss.size())){
      cout << "no\n";
      return 0;
    }
    ++iss;
    ++is;
  }
  
  cout << "yes\n";

}
