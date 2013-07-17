#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

const double pi=2*acos(0);

int main(){
  double D,V;
  while(cin >> D >> V && (D!=0 || V!=0)){
    double ddd=D*D*D-6*V/pi;
    cout << fixed << setprecision(3) << pow(ddd,double(1)/double(3)) << '\n';
  }
}
