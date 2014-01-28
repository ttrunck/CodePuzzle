#include<iostream>
#include<string>

using namespace std;

bool good(const string& s){
  for(int i=0;i<int(s.size())-2;++i)
    if((s[i]=='1' && s[i+1]=='0' && s[i+2]=='1')
       || (s[i]=='0' && s[i+1]=='1' && s[i+2]=='0'))
      return true;
  return false;
}

int main(){
  int n;
  cin >> n;
  for(int i=0;i<n;++i){
    string s;
    cin >> s;
    if(good(s))
      cout << "Good\n";
    else
      cout << "Bad\n";
    
  }
}
