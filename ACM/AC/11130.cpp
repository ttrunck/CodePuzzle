#include<iostream>
#include<cmath>

using namespace std;

const double PI=atan(1)*4;

void aux(double a, double b, double v, double A, double s){
  double d=s*v-s*v/2;
  double x=a/2+d*cos(A*PI/180);
  double y=b/2+d*sin(A*PI/180);
  cout << int(x/a) << ' ' << int(y/b) << '\n';
}


int main(){
  double a,b,v,A,s;
  while(cin >> a >> b >> v >> A >> s &&(a|| b||v||A||s)){
    aux(a,b,v,A,s);
  }
}
