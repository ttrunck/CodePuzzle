#include<iostream>
#include<cmath>

using namespace std;

int sum(int n){
 int res=0;
  while(n!=0){
    res+=n%10;
    n/=10;
  }
  return res;
}

bool smith(const int n){
  int res=0;
  bool prime=true;
  
  int nn=n;
  int curr=2;
  while(nn!=1 && curr<=sqrt(n)){
    if(nn%curr==0){
      res+=sum(curr);
      nn/=curr;
    }
    else
      curr++;
  }

  prime=(n==nn);
  if(nn!=1)
    res+=sum(nn);

  return (!prime && (res==sum(n)));
}

int main(){
  int icas;
  cin >> icas;
  while(icas--){
    int n;
    cin >> n;
    ++n;
    while(!smith(n))++n;
    cout << n << '\n';
  }
}
