#include<iostream>
#include<string>
#include<map>
#include<cmath>
#include<iomanip>

using namespace std;

typedef pair<double, double> pf;

const double R=6378;
const double pi=3.141592653589793;

double dist(pf x, pf y){
 double lat1= x.first*pi/180;
 double lon1= x.second*pi/180;
 double lat2= y.first*pi/180;
 double lon2= y.second*pi/180;

 double dlon = lon2 - lon1;
 double dlat = lat2 - lat1;
 double a = sin(dlat/2)*sin(dlat/2) + cos(lat1) * cos(lat2) * sin(dlon/2)*sin(dlon/2);
 return R* 2 * atan2(sqrt(a), sqrt(1-a)) ;
  //  return R*acos(cos(x.first)*cos(x.second)*cos(y.first)*cos(y.second)
  //		+cos(x.first)*sin(x.second)*cos(y.first)*sin(y.second)+
  //		sin(x.first)*sin(y.first));
}

int main(){
  map<string, pf> m;
  string s;
  while(cin >> s && s!="#"){
    double a,b;
    cin >> a >> b;
    m[s]=pf(a,b);
  }

  string a,b;
  while(cin >> a >> b && (a!="#" || b!="#")){
    cout << a << " - " << b << '\n';
    if(m.find(a)==m.end() || m.find(b)==m.end())
      cout << "Unknown\n";
    else
      cout << long(dist(m[a], m[b])+0.5) << " km\n";
    
  }
}
