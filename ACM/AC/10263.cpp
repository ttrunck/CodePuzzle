#include<iostream>
#include<iomanip>
#include<cmath>
#include<vector>
#include<utility>

using namespace std;

double mx,my;
double resx,resy;
double dist=1e20;

void calc(const pair<double, double> & a, const pair<double, double> & b){
  double L2=(b.first-a.first)*(b.first-a.first)+(b.second-a.second)*(b.second-a.second);
  double r=((a.second-my)*(a.second-b.second)-(a.first-mx)*(b.first-a.first))/L2;

  double px,py;
  if(r>1){
    px=b.first;
    py=b.second;
  }
  else if(r<0){
    px=a.first;
    py=a.second;
  }
  else{
    px=a.first+r*(b.first-a.first);
    py=a.second+r*(b.second-a.second);
  }

  double distcurr=sqrt((px-mx)*(px-mx)+(py-my)*(py-my));
  if(distcurr<dist){
    resx=px;
    resy=py;
    dist=distcurr;
  }
}

int main(){
 
  while(cin >> mx >> my){
    int N;
    cin >> N;
    vector<pair<double, double> > t(N+1);
    for(int i=0;i<N+1;++i)
      cin >> t[i].first >> t[i].second;

    dist=1e20;
    for(int i=1;i<int(t.size());++i){
      calc(t[i-1], t[i]);
    }
    cout << fixed << setprecision(4) << resx << '\n' << resy << '\n';
  }
}
