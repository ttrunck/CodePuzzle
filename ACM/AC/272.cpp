#include<iostream>
#include<cstdio>

using namespace std;

int main(){
  bool first=true;
  char c;
  cin >> noskipws;
  while(cin >> c){
    if(c=='\"'){
      if(first){
	cout << "``";
	first=false;
      }
      else{
	cout << "''";
	first=true;
      }
    }
    else
      cout << c;
  }
}
