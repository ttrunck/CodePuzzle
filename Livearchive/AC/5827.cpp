#include<iostream>
#include<cmath>
#include<utility>
#include<cstdio>

using namespace std;

const double pi=acos(-1);
const double epsi=1e-4;

pair<double, double> inter(const pair<double, double> & a, const pair<double, double> & b, const pair<double, double> & c, const pair<double, double> & d){
  double r=((a.second-c.second)*(d.first-c.first)-(a.first-c.first)*(d.second-c.second))/
    ((b.first-a.first)*(d.second-c.second)-(b.second-a.second)*(d.first-c.first));
  return make_pair(a.first+r*(b.first-a.first), a.second+r*(b.second-a.second));
}

double angle(pair<double, double> m, double ax, double ay, double bx, double by){
  return atan2(ay-m.second,ax-m.first)-atan2(by-m.second, bx-m.first);
}

int main(){
  double ax,ay,bx,by,cx,cy;
  while(scanf("%lf %lf %lf %lf %lf %lf",&ax,&ay,&bx,&by,&cx,&cy)){

    pair<double, double> a,b,c,d;
    a=make_pair((ax+bx)/2, (ay+by)/2);
    b=make_pair(a.first+by-ay, a.second-(bx-ax));
    c=make_pair((ax+cx)/2, (ay+cy)/2);
    d=make_pair(c.first+cy-ay, c.second-(cx-ax));
    pair<double, double> m=inter(a,b,c,d);

    double ang1=angle(m,ax,ay,bx,by);
    double ang2=angle(m,ax,ay,cx,cy);
    if(ang1<0) ang1+=2*pi;
    if(ang2<0) ang2+=2*pi;
    int res=3;
    while(true){
      double k1=ang1*res/(2*pi);
      double k2=ang2*res/(2*pi);
      if((k1-floor(k1+epsi))<epsi && (k2-floor(k2+epsi))<epsi) break;
      res++;
    }
  
    printf("%d\n",res);
  }
}
