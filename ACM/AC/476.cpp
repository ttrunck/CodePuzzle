#include<iostream>
#include<vector>

using namespace std;

struct rect{
  double a,b,c,d;
  rect(double aa, double bb, double cc, double dd):a(aa),b(bb),c(cc),d(dd){};
};

bool conti(double x, double y, const rect & r){
  return (r.a<x && x<r.c && y<r.b && r.d<y);
}


int main(){
  char c;
  vector<rect> t;
  while(cin >> c && c=='r'){
    double a,b,c,d;
    cin >> a >> b >> c >> d;
    t.push_back(rect(a,b,c,d));
  }

  double x,y;
  int pcout=1;
  while(cin >> x >> y && (x!=9999.9 || y!=9999.9)){
    bool cont=false;
    for(int i=0;i<int(t.size());++i)
      if(conti(x,y,t[i])){
	cont=true;
	cout << "Point " << pcout << " is contained in figure " << i+1 << '\n';
      }

    if(!cont){
      cout << "Point " << pcout << " is not contained in any figure\n";
    }
    pcout++;
  }
}
