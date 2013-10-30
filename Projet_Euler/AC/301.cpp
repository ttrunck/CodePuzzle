#include<iostream>

using namespace std;

typedef long long ll;

int main(){
  int res=0;
  for(ll i=1;i<=(1<<30);++i)
    if((i^(2*i)^(3*i))==0)
      ++res;
  cout << res << '\n';
}
