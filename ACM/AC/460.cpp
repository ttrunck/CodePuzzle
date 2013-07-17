#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){
  int n;
  cin >> n;
  bool first=true;
  while(n--){
    if(!first)
      cout << '\n';
    first=false;
    int ax,ay,bx,by,cx,cy,dx,dy;
    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
    int ex=max(ax,cx),ey=max(ay,cy),fx=min(bx,dx),fy=min(by,dy);
    if(ex<fx && ey < fy)
      cout << ex << ' ' << ey << ' ' << fx << ' ' << fy << '\n';
    else
      cout << "No Overlap\n";
  }
}
