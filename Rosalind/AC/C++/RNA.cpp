#include<iostream>
#include<string>

using namespace std;

int main(){
  string s;
  cin >> s;
  for(int i=0;i<int(s.size());++i)
    if(s[i]=='T') s[i]='U';
  cout << s << endl;
}
