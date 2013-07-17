#include<iostream>
#include<string>

using namespace std;

int main(){
  string s;
  cin >> s;
  for(int i=0;i<int(s.size());++i){
    if(s[i]=='A') s[i]='T';
    else if(s[i]=='T') s[i]='A';
    else if(s[i]=='C') s[i]='G';
    else s[i]='C';
  }
  for(int i=int(s.size())-1;i>=0;--i)
    cout << s[i];
  cout << '\n';
}
