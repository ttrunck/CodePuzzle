#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

const double pi=2*acos(0);

int main(){
  double x=1;
    double ax,ay,bx,by,cx,cy;
    ax=x/2;
    ay=0;
    bx=ax+x*cos(2*pi/5);
    by=ay+x*sin(2*pi/5);
    cx=bx-x*cos(pi/5);
    cy=by+x*sin(pi/5);

    //cerr << fixed << setprecision(10) << ax << ' ' << ay << ' ' << bx << ' ' << by << ' ' << cx << ' ' << cy << endl;

    double lo=0, hi=cy;
    while(hi-lo>1e-14){
      double mx=(lo+hi)/2, my=cy-(lo+hi)/2;
      // cerr << mx << ' ' << my << endl;
      if(((bx-ax)*(my-ay)-(by-ay)*(mx-ax))>0)
	lo=(lo+hi)/2;
      else
	hi=(lo+hi)/2;
    }
    
    double res=2*lo/sqrt(2);
    double y;
    while(cin >> y){
      cout << fixed << setprecision(10) << res*y << '\n';
  }
}
