#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

const double pi=2*asin(1);

int main(){
  double a,b,c;
  while(cin >> a >> b >> c){
    double p=a+b+c;
    double s=sqrt(p/2*(p/2-a)*(p/2-b)*(p/2-c));
    double r=2*s/p;
    double R=a*b*c/(4*s);

    cout << fixed << setprecision(4) << pi*R*R-s << ' ' << s-pi*r*r << ' ' << pi*r*r << '\n';

  }
}
