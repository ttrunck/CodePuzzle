#include<iostream>
#include<cmath>

using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  
  int aa=0,e=0,bb=0;
  
  for(int i=1;i<=6;++i)
    if(abs(a-i)<abs(b-i))
      ++aa;
    else if(abs(a-i)==abs(b-i))
      ++e;
    else
      ++bb;

  cout << aa << ' ' << e << ' ' << bb << '\n';
}
