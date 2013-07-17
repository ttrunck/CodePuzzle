#include<iostream>
#include<string>

using namespace std;

int main(){
  string s;
  cin >> s;
  int a=0,c=0,g=0,t=0;
  for(int i=0;i<int(s.size());++i){
    if(s[i]=='A') ++a;
    if(s[i]=='C') ++c;
    if(s[i]=='G') ++g;
    if(s[i]=='T') ++t;
  }
  cout << a << ' ' << c << ' ' << g << ' ' << t << endl;
}
