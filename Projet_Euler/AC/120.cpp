#include<iostream>
#include<cmath>

using namespace std;

int calc(int a, int n){
  if(n%2==0) return 2;
  else return (2*n*a);
}

int aux(int a){
  int res=0;
  int aa=a*a;
  for(int n=0;n<a*a;++n){
    int tmp=(calc(a, n)+aa)%aa;
    res=max(res, tmp);
  }
  return res;
}

int main(){
  int res=0;
  for(int a=3;a<=1000;++a){
    int tmp=aux(a);
    // cout << tmp << ' ';
    res+=tmp;
  }
  cout << res << '\n';
}
