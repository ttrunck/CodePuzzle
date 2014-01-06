#include<iostream>

using namespace std;

int abs(int a){
  return (a>0)?a:-a;
}

int main(){
  int a,b,x,y;
  cin >> a >> b >> x >> y;

  cout << ((a==x)?0:1) + ((b==y)?0:1) << ' ';
  if(abs(a-b)%2!=abs(x-y)%2)
    cout << "0 ";
  else if(a-x==b-y || a-x==y-b)
    cout << "1 ";
  else
    cout << "2 ";
  
  cout << max(abs(a-x),abs(b-y)) << '\n';
}
