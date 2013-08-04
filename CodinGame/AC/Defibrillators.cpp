#include<iostream>
#include<string>
#include<sstream>
#include<cmath>
#include<limits>

using namespace std;

double conv(string & s){
  for(int i=0;i<int(s.size());++i)
    if(s[i]==',')
      s[i]='.';
  double res;
  stringstream(s) >> res;
  return res;
}

double dist(double lon1, double lat1, double lon2, double lat2){
  double x=(lon2-lon1)*cos((lat1+lat2)/2);
  double y=lat2-lat1;
  return sqrt(x*x+y*y)*6371;
}

int main(){
  string xx, yy;
  getline(cin, xx);
  getline(cin, yy);
  double x=conv(xx),y=conv(yy);
  int N;
  cin >> N;
  cin.ignore();
  double distmin=numeric_limits<double>::max();
  string name_res;
  for(int i=0;i<N;++i){
    string s;
    getline(cin, s);
    stringstream ss(s);
    string tmp, name, slon, slat;
    getline(ss, tmp, ';');
    getline(ss, name, ';');
    getline(ss, tmp, ';');
    getline(ss, tmp, ';');
    getline(ss, slon, ';');
    getline(ss, slat, ';');
    double lon=conv(slon), lat=conv(slat);
    double tmp1=dist(x,y,lon,lat);
    if(tmp1<distmin){
      distmin=tmp1;
      name_res=name;
    }
  }
  cout << name_res << endl;
}
