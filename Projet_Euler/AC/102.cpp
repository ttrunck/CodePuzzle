#include<iostream>

using namespace std;

int det(int ax,int ay, int bx, int by, int cx, int cy, int dx, int dy){
  return (bx-ax)*(dy-cy)-(by-ay)*(dx-cx);
}

int contains(int ax, int ay, int bx, int by, int cx, int cy){
  if(det(ax,ay,bx,by,ax,ay,cx,cy)>=0)
  return (
	  det(ax,ay,bx,by,ax,ay,0,0)>=0
	  && det(bx,by,cx,cy,bx,by,0,0)>=0
	  && det(cx,cy,ax,ay,cx,cy,0,0)>=0
	  );
  return  (
	  det(ax,ay,bx,by,ax,ay,0,0)<=0
	  && det(bx,by,cx,cy,bx,by,0,0)<=0
	  && det(cx,cy,ax,ay,cx,cy,0,0)<=0
	  );
}

int main(){
  int res=0;
  int ax,ay,bx,by,cx,cy;
  while(cin >> ax >> ay >> bx >> by >> cx >> cy){
    if(contains(ax,ay,bx,by,cx,cy)) res++;
    cout << contains(ax,ay,bx,by,cx,cy) << '\n';
  }
  cout << res << '\n';
}
