#include<iostream>

using namespace std;

typedef long long ent;

int vu[10];

bool check(ent nn, ent n){
  for(int i=0;i<10;++i) vu[i]=0;
  while(nn!=0){
    vu[nn%10]++;
    nn/=10;
  }
  while(n!=0){
    vu[n%10]--;
    n/=10;
  }
  for(int i=0;i<10;++i)
    if(vu[i]!=0) return false; 
return true;
}

bool ok(ent n){
  return check(n,2*n) && check(n,3*n) && check(n,4*n) && check(n,5*n) && check(n,6*n);
}

int main(){
  ent i=1;
  while(!ok(i)){
    if(i%10000000==0) cout << i << '\n';
 ++i;
  }
  cout << i << '\n';
}
