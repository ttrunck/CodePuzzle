#include<iostream>
#include<set>
#include<vector>
#include<cmath>
#include<complex>

using namespace std;

typedef pair<int, int> point;

const double eps = 1e-10;

inline double det(const point& a, const point& b){
  return a.first*b.second-a.second*b.first;
}

point operator-(const point& a, const point& b){
  return point(a.first-b.first, a.second-b.second);
}

// Return true iff [a,b] intersects [c,d]
bool intersectSegment(const point &a, const point &b, const point &c, const point &d){
  double x = det(c - a, d - c);
  double y = det(b - a, a - c);
  double z = det(b - a, d - c);
  if(!(abs(z) < eps || x*z < 0 || x*z > z*z || y*z < 0 || y*z > z*z))
    return true;

  if(abs(z)<eps && abs(det(d-a, b-a))<eps){
    //ils sont colineaire
    if((min(a,b)<=c && c<=max(a,b)) || (min(a,b)<=d && d<=max(a,b)))
      return true;
  }
  return false;
}

double dist(const point& a, const point&b){
  return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

int main(){
  ios::sync_with_stdio(false);
  int nbcase;
  cin >> nbcase;
  while(nbcase--){
    int s,r,w,p;
    cin >> s >> r >> w >> p;
    set<point> sensors;
    for(int i=0;i<s;++i){
      int x, y;
      cin >> x >> y;
      sensors.insert(point(x,y));
    }
    vector<pair<point, point> > walls(w);
    for(int i=0;i<w;++i){
      int b1, b2, e1, e2;
      cin >> b1 >> b2 >> e1 >> e2;
      walls[i]= pair<point, point>(point(b1, b2), point(e1, e2));
    }

    for(int nbproduit=0;nbproduit<p;++nbproduit){
      int x,y;
      cin >> x >> y;
      point prod=point(x,y);
      vector<point> res;
      for(int i=x-r;i<=x+r;++i)
	for(int j=y-r;j<=y+r;++j){
	  point sensor=point(i,j);
	  if(sensors.find(sensor)!=sensors.end()){
	    double distance=dist(prod, sensor);
	    int mur=0;
	    for(int k=0;k<w;++k)
	      if(intersectSegment(prod, sensor, walls[k].first, walls[k].second))
		mur++;
	    //  cerr << "sensor trouvé " << x << ',' << y << ' ' << i << ',' << j << endl;
	    //cerr << "la distance est " << distance << " et il y a mur " << mur << endl;
	    if(distance+mur<=r)
	      res.push_back(sensor);
	  }
	}

      cout << res.size();
      for(int i=0;i<int(res.size());++i)
	cout << " (" << res[i].first << ',' << res[i].second << ')';
      cout << '\n';
    }
  }
}
