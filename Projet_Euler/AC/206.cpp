#include<iostream>

using namespace std;

typedef long long ent;

bool ok(ent n){
  if(n%10!=0) return false;
  n=n/100;
  for(int i=9;i>0;--i){
    if(n%10!=i) return false;
    n/=100;
  }
  return true;
}

int main(){
  for(ent i=100000000;i<10000000000;i+=10)
    if(ok(i*i)){cout << i << ' ' << i*i << '\n'; break;}
}
