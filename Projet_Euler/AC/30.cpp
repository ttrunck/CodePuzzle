#include <iostream>
#include <cmath>

using namespace std;

int const N=1000000;

bool is_power5(int n){
  int nn=n;
  int res=0;
  while(n!=0){
    res+=pow(n%10,5);
    n/=10;
  }
  return nn==res;
}

int main(){
  int res=0;
  for(int i=10;i<N;++i)
    if(is_power5(i)){
      res+=i;
      cout << i << '\n';
    }

  cout << '\n' << res << '\n';
}
