#include<iostream>
#include<cmath>

using namespace std;

int solve(double n){
  double x=2./(n+1);
  double res=x;
  for(int i=2;i<=n;++i)
    res*=pow(i*x,i);
  return res;
}

int main(){
  int res=0;
  for(int i=2;i<=15;++i)
    res+=solve(i);
  cerr << res << endl;
}
