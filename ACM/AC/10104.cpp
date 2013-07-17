#include<iostream>
#include<cmath>

using namespace std;

struct triple{
  int x,y,d;
  triple(int xx,int yy,int dd){
    x=xx;y=yy;d=dd;
  }
};

triple gcd(int r,int u,int v,int rr,int uu,int vv){
  if(rr==0)
    return triple(u,v,r);
  else
    return gcd(rr,uu,vv,r-(r/rr)*rr,u-(r/rr)*uu,v-(r/rr)*vv);
}

int main(){
  int a,b;
  int x,y,d;
  while(cin >> a >> b){
    triple t= gcd(a,1,0,b,0,1);
    cout << t.x << ' ' << t.y << ' ' << t.d << endl;
  }
}
