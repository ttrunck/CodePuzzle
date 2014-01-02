#include<iostream>

using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  int out=0;
  int res=0;
  while(a!=0){
    res+=a;
    out+=a;
    a=out/b;
    out=out%b;
  }
  cout << res << '\n';
}

