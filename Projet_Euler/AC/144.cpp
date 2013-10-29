#include<iostream>
#include<cmath>

using namespace std;

const double raddeg = 180/3.14259;
const double PI=4*atan(1);

int main(){
  double xa=0, ya=10.1;
  double xb=1.4, yb=-9.6;
  int res=0;
  while(abs(xb)>0.01 || yb<0){
    ++res;

    double A=(yb-ya)/(xb-xa);
    double ellip=-4*xb/yb;
    
    A = atan2(ya-yb, xa-xb);
    ellip = atan2(-4*xb/yb, 1);
    double B=tan(2*ellip-A+PI);
 
    double a=B*B+4;
    double b=2*B*(yb-B*xb);
    double c=(yb-B*xb)*(yb-B*xb)-100;
 
    double sqdelta=sqrt(b*b-4*a*c);
    double res1=(-b+sqdelta)/(2*a); 
    double res2=(-b-sqdelta)/(2*a); 
 
    xa=xb;
    ya=yb;
 
    xb=(abs(res1-xb)>abs(res2-xb))?res1:res2;
    yb=B*xb+(yb-B*xa);
 
  }
  cout << res << '\n';
}
