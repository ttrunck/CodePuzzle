#include<iostream>

using namespace std;

int main(){
  int cas;
  cin >> cas;
  while(cas--){
    long long a,b;
    cin >> a >> b;
    if(a==b)
      cout << "=\n";
    else if (a<b)
      cout << "<\n";
    else
      cout << ">\n";
  }
}
