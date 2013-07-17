#include<iostream>
#include<utility>
#include<iomanip>
#include<algorithm>
#include<cmath>

using namespace std;

typedef pair<double, double> pf;
const double eps=1e-6;

pf inter(const pf & a, const pf & b, const pf & c, const pf & d){
  double den=(b.first-a.first)*(d.second-c.second)-(b.second-a.second)*(d.first-c.first);
  double num1=(a.second-c.second)*(d.first-c.first)-(a.first-c.first)*(d.second-c.second);
  double r=num1/den;
  return pf(a.first+r*(b.first-a.first), a.second+r*(b.second-a.second));
}

double x, y, c;

double calc(double s){
  pf a(0,0);
  pf c(s,0);
  pf b(s,sqrt(x*x-s*s));
  pf d(0,sqrt(y*y-s*s));
  return inter(a,b,c,d).second;
}

int main(){
  while(cin >> x >> y >> c){
    double hi=min(x,y);
    double lo=0;
    double tmp;
    do{
      tmp=calc((hi+lo)/2);
      if(tmp>c)
	lo=(hi+lo)/2;
      else
	hi=(hi+lo)/2;
    }while(abs(c-tmp)>eps);
    cout << fixed << setprecision(3) << lo << '\n';
  }
}
