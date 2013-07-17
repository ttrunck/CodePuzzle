#include<iostream>
#include<cmath>

using namespace std;

const double R=6371009;
const double pi=2*acos(0);

double dist(double lat1, double lon1, double lat2, double lon2){
 double dlon = lon2 - lon1;
 double dlat = lat2 - lat1;
 double a = sin(dlat/2)*sin(dlat/2) + cos(lat1) * cos(lat2) * sin(dlon/2)*sin(dlon/2);
 return R* 2 * atan2(sqrt(a), sqrt(1-a)) ;
}

double aux(double lat1, double lon1, double lat2, double lon2){
  double z1=sin(lat1)*R;
  double x1=R*cos(lon1)*cos(lat1);
  double y1=R*sin(lon1)*cos(lat1);
  double z2=sin(lat2)*R;
  double x2=R*cos(lon2)*cos(lat2);
  double y2=R*sin(lon2)*cos(lat2);
  return sqrt((z1-z2)*(z1-z2)+(y1-y2)*(y1-y2)+(x1-x2)*(x1-x2));
}

int main(){
  int n;
  cin >> n;
  while(n--){
    double lat1, lon1, lat2, lon2;
    cin >> lat1 >> lon1 >> lat2 >> lon2;
    lat1*=pi/180;
    lon1*=pi/180;
    lat2*=pi/180;
    lon2*=pi/180;
    // cerr << lat1 << ' ' << lon1 << ' ' << lat2 << ' ' << lon2 << endl;
    // cerr << dist(lat1,lon1,lat2,lon2) << ' ' << dist(lat1,lon1,lat2,lon2) << endl;
    // cerr << aux(lat1,lon1,lat2,lon2) << ' ' << aux(lat1,lon1,lat2,lon2) << endl;
    cout << int(dist(lat1,lon1,lat2,lon2)-aux(lat1,lon1,lat2,lon2)+0.5) << '\n';
  }
}
