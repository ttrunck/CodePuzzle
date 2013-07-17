#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

const double eps=1e-9;

double calc(double L, double W){
  double res=L;
  double ang=atan2(W/2,L/2);
  double dist=sqrt(W*W/4+L*L/4);
  res+=2*dist*ang;

  return 2*res;
}

int main(){
  int icase=1;
  char tmp;
  double a,b;
  while(cin >> a >> tmp >> b){
    cout << "Case " << icase++ << ": ";
    double lo=0,hi=400;
    double size;
    do{
      double L=(lo+hi)/2;
      size=calc(L, L*b/a);
      if(size>400)
	hi=L;
      else
	lo=L;
    }while(abs(size-400)>eps);
    cout << fixed << setprecision(8) << lo << ' ' << lo*b/a << '\n';
  }
}
