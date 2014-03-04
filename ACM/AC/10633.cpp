#include<iostream>

typedef unsigned long long ent;

using namespace std;

int main(){
  ent n;
  while(cin >> n && n){
    ent x=10*n/9;
    bool first=true;
    for(ent m=x-10;m<=x+10;++m)
      if(m-m/10==n){
	if(!first)
	  cout << ' ';
	first=false;
	cout << m;
      }
    cout << '\n';
  }
}
