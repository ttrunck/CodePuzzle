#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;
 
int p,q,r,s,t,u;

double f(double x){
  return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

double bisec(){
  const double epsi=1e-7;
  double hi=1, lo=0;
  while(hi-lo>epsi){
    double x=(hi+lo)/2;
    if(f(lo)*f(x)<=0)
      hi=x;
    else
      lo=x;
  }
  return lo;
}

int main(){

 while(cin >> p >> q >> r >> s >> t >> u){
   if(f(0)*f(1)>0)
     cout << "No solution" << endl;
   else
     cout << setprecision(4) << fixed << bisec() << endl;

 }
}
