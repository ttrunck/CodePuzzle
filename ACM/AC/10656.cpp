#include<iostream>

using namespace std;

int main(){
  int n;
  while(cin >> n && n){
    bool first=true;
    for(int i=0;i<n;++i){
      int tmp;
      cin >> tmp;
      if(tmp>0){
	if(!first)
	  cout << ' ';
	first=false;
	cout << tmp;
      }
    }
    if(first)
      cout << '0';
    cout << '\n';
  }
}
