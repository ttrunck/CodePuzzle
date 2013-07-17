#include<iostream>
#include<cmath>
#include<iomanip>
#include<utility>

using namespace std;

void print(double x){
  if(x>=0) cout << "+ ";
  else cout << "- ";
  cout << fixed << setprecision(3) << abs(x);
}

pair<double, double> inter(const pair<double, double> & a, const pair<double, double> & b, const pair<double, double> & c, const pair<double, double> & d){
  double r=((a.second-c.second)*(d.first-c.first)-(a.first-c.first)*(d.second-c.second))/
    ((b.first-a.first)*(d.second-c.second)-(b.second-a.second)*(d.first-c.first));
  return make_pair(a.first+r*(b.first-a.first), a.second+r*(b.second-a.second));
}

int main(){
  double ax,ay,bx,by,cx,cy;
  while(cin >> ax >> ay >> bx >> by >> cx >> cy){

    double h,k,r;
    
    {
    pair<double, double> a,b,c,d;
    a=make_pair((ax+bx)/2, (ay+by)/2);
    b=make_pair(a.first+by-ay, a.second-(bx-ax));
    c=make_pair((ax+cx)/2, (ay+cy)/2);
    d=make_pair(c.first+cy-ay, c.second-(cx-ax));
    

    pair<double, double> m=inter(a,b,c,d);
    h=m.first;
    k=m.second;
    r=sqrt((ax-m.first)*(ax-m.first)+(ay-m.second)*(ay-m.second));
    }
    double c=-2*h,d=-2*k,e=h*h+k*k-r*r;
    cout << "(x ";
    print(-h);
    cout << ")^2 + (y ";
    print(-k);
    cout << ")^2 = " << fixed << setprecision(3) << r << "^2\n";
    
    cout << "x^2 + y^2 ";
    print(c);
    cout << "x ";
    print(d);
    cout << "y ";
    print(e);
    cout << " = 0\n\n";
  }
}
