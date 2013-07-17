#include<iostream>
#include<string>

using namespace std;

const int N=131071;

int main(){
  char c;
  string s;
  while(cin >> c){
    if(c=='#'){
      // cerr << s << endl;
      int res=0;
      int curr=1;
      for(int i=s.size()-1;i>=0;--i){
	if(s[i]=='1')
	  res=(res+curr)%N;
	curr=(curr*2)%N;
      }
      if(res==0)
	cout << "YES\n";
      else
	cout << "NO\n";
      s.clear();
    }
    else
      s.push_back(c);
  }
}
