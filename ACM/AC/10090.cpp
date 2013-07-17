#include<iostream>
#include<limits>
#include<cmath>
#include<cassert>

using namespace std;

typedef long long ent;

void extendedeuclide(ent a, ent b, ent & x, ent & y, ent & d){
  if(b==0){
    x=1;y=0;d=a;
  }
  else{
    ent xx, yy;
    extendedeuclide(b, a%b, xx, yy, d);
    x=yy; y=xx-yy*(a/b);
  }
  return;
}

int main(){
  ent n;
  while(cin >> n && n){
    ent c1, n1, c2, n2;
    cin >> c1 >> n1 >> c2 >> n2;
    ent x, y, d;
    extendedeuclide(n1, n2, x, y, d);
    // cerr << n1 << ' ' << x << ' ' << n2 << ' ' << y << ' ' << d << endl;
    if(n%d!=0)
      cout << "failed\n";
    else{
      ent resx=(n/d)*x, resy=(n/d)*y;
      ent d1=n1/d, d2=n2/d;
      //   cerr << resx << ' ' << resy << endl;
      ent k1=(-resx>0)?(-resx+d2-1)/d2:-resx/d2;
      ent k2=(resy>0)?resy/d1:(resy-d1+1)/d1;
      //je veux k2<=k<=k1;
      // cerr << "k1 k2 " << k1 << ' ' << k2 << endl;
      if(k1>k2)
	cout << "failed\n";
      else if(c1*(resx+k1*d2)+c2*(resy-k1*d1)<=c1*(resx+k2*d2)+c2*(resy-k2*d1)){
	cerr << "cas1 ";
	cout << resx+k1*d2 << ' ' << resy-k1*d1 << '\n';
      }
      else{
	cerr << "cas2 ";
	cout << resx+k2*d2 << ' ' << resy-k2*d1 << '\n';
      }
    }
  }
}
