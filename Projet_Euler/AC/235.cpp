#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

double eval(double r){
  double res=0;
  for(int i=1;i<=5000;++i)
    res+=(900-(3*i))*pow(r,i-1);
  return res;
}

double const eps=1e-15;
double N=-600000000000;

int main(){
  double lo=1,hi=1.5;
  while(hi-lo>eps){
    double x=(hi+lo)/2;
    double tmp = eval(x);
    if(tmp<N)
      hi=x;
    else
      lo=x;
  }

  cerr << eval(lo) << endl;

  cout << fixed << setprecision(12) << lo << endl;
}
