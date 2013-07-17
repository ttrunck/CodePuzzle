#include<iostream>
#include<vector>
#include<limits>

using namespace std;

typedef long long ent;

ent perfect(ent x, ent y, ent m){
  // cerr << x << ' ' << y << endl;
  if(x>=m) return 0;
  if(x<=0) return -1;
  if(y<0) return (-y+x)/x+perfect(x,y+((-y+x)/x)*x,m);

  return 1+perfect(max(x+y,x),min(x+y,x),m);

}

int main(){
  ent x,y,m;
  cin >> x >> y >> m;
  cout << perfect(max(x,y),min(x,y),m) << '\n';

}
