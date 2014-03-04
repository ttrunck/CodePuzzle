#include <iostream>

using namespace std;

struct Point {
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  Point operator-(const Point& p) const {return Point(x-p.x, y-p.y);}
  bool operator<=(const Point& p) const {
    return x<=p.x || (x==p.x && y<=p.y);
  }
};

double det(const Point& p1, const Point& p2) {
  return p1.x*p2.y-p1.y*p2.x;
}

bool inter(const Point& a,const Point& b,const Point& c,const Point& d) {
  if (det(b-a, d-c) == 0) {
    if(det(b-a, c-a))
      return ((a<=c && c<=b) || (a<=d && d<=b) || (b<=c && c<=a) || (b<=d && d<=a));
    else
      return false;
  }
  return det(b-a, c-a)*det(b-a, d-a) <= 0 &&
         det(d-c, a-c)*det(d-c, b-c) <= 0;
}

int main(){
  int n;
  cin >> n;
  while(n--){
    double xs,ys,xe,ye,xl,yt,xr,yb;
    cin >> xs >> ys >> xe >> ye >> xl >> yt >> xr >> yb;
    if(xl>xr) swap(xl,xr);
    if(yb>yt) swap(yb,yt);
    bool inte=
      inter(Point(xs,ys),Point(xe,ye),Point(xl,yb),Point(xr,yb))
      ||inter(Point(xs,ys),Point(xe,ye),Point(xl,yt),Point(xr,yt))
      ||inter(Point(xs,ys),Point(xe,ye),Point(xl,yb),Point(xl,yt))
      ||inter(Point(xs,ys),Point(xe,ye),Point(xr,yb),Point(xr,yt))
      ||(xl<=xs && xs<=xr && yb<=ys && ys<=yt) 
      ||(xl<=xe && xe<=xr && yb<=ye && ye<=yt);
 cout << (inte?'T':'F') << endl;
    
  }
}
