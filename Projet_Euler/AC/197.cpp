#include<iostream>
#include<cmath>
#include<iomanip>


using namespace std;

double f(double x){
  return floor(pow(2,30.403243784-x*x))*1e-9;
}

const double eps=1e-12;

int main(){
  double u0=-1, u1=f(u0);
  while(abs(u0-f(u1))>eps){
    cerr << u0 << endl;
    u0=u1;
    u1=f(u1);
  }
  cout << fixed << setprecision(9) << u0+u1 << '\n';
}
