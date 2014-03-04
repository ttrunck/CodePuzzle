#include<iostream>
#include<cmath>
#include<utility>
#include<vector>

using namespace std;

double epsi=1e-10;

inline double dist(const pair<double, double> a, const pair<double, double> b){
  return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

int main(){
  int n;
  while(cin >> n && n){
    vector<pair<double, double> > t(n);
    for(int i=0;i<n;++i)
      cin >> t[i].first >> t[i].second;
    double r;
    cin >> r;


    bool res=false;
    for(int i=0;i<n;++i)
      for(int j=i+1;j<n;++j){
	if(dist(t[i], t[j])>2*r+epsi){
	  res=false;
	  goto paf;
	}

	else{
	  pair<double, double> c=make_pair((t[i].first+t[j].first)/2,(t[i].second+t[j].second)/2);
	  double xx=-t[i].second+t[j].second, yy=t[i].first-t[j].first;
	  double norm=sqrt(xx*xx+yy*yy);
	  xx=xx/norm;
	  yy=yy/norm;
	  double r1=norm/2;
	  double r2=sqrt(r*r-r1*r1);

	  pair<double, double> c1=make_pair(c.first+r2*xx, c.second+r2*yy);
	  bool ok=true;
	  for(int k=0;k<n;++k)
	    if(dist(c1,t[k])>r+epsi){
	      ok=false;
	      break;
	    }
	  if(ok){
	    res=true;
	    goto paf;
	  }

	  ok=true;
	  pair<double, double> c2=make_pair(c.first-r2*xx, c.second-r2*yy);
	  for(int k=0;k<n;++k)
	    if(dist(c2,t[k])>r-epsi){
	      ok=false;
	      break;
	    }
	  if(ok){
	    res=true;
	    goto paf;
	  }
	}
      }
  paf:

    if(n==1) res=true;
    if(res) cout << "The polygon can be packed in the circle.\n";
    else cout << "There is no way of packing that polygon.\n";

  }
}
