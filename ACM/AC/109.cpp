#include<iostream>
#include<algorithm>
#include<complex>
#include<vector>
#include<iomanip>

using namespace std;

typedef complex<double> point;
typedef vector<point> poly;

const double eps=1e-8;
double inline det(const point &u, const point &v) { return imag(conj(u) * v); }

// Return true iff [a,b] intersects [c,d], and store the intersection in ans
bool intersectSegment(const point &a, const point &b, const point &c, const point &d) {
  double x = det(c - a, d - c);
  double y = det(b - a, a - c);
  double z = det(b - a, d - c);
  if (abs(z) < eps || x*z < 0 || x*z > z*z || y*z < 0 || y*z > z*z) return false;
  return true;
}

point outside(1000, 1000); // A point outside the workspace
bool isInside(const point &a, const poly &p) {
  int n = p.size();
  bool tmp, ans = false;
  for(int i=0;i<int(p.size());++i){
    tmp = intersectSegment(a, outside, p[i], p[(i + 1) % n]);
    ans = (ans != tmp);
  }
  return ans;
}

double computeArea(poly &t){
  double sum = 0;
  for (int i = 1; i < int(t.size()) - 1; ++i)
    sum += det(t[i] - t[0], t[i + 1] - t[0]);
  return abs(sum / 2);
}

struct Compare{
  point p0; // Leftmost point of the poly
  bool operator ()(const point &p1, const point &p2) {
    if (p1 == p0) return true;
    if (p2 == p0) return false;
    double d = det(p1-p0, p2-p0);
    return (d<0 || (d==0 && abs(p1-p0) < abs(p2-p0)));
  }
};

bool inline salientAngle(const point & a, const point & b, const point & c) {
  return (det(b-a, c-a) >= 0);
}

void convexHull(poly &t, poly &r){
  Compare order;
  order.p0 = t[0];
  for(int i=0;i<int(t.size());++i)
    if (t[i].real() < order.p0.real())
      order.p0 = t[i];
  sort(t.begin(), t.end(), order);
  for(int i=0; i<int(t.size());++i){
    r.push_back(t[i]);
    while (r.size() > 3 && salientAngle(r.end()[-3], r.end()[-2], r.end()[-1])) {
      r.end()[-2] = r.back();
      r.pop_back();
    }
  }
}

int main(){
  int n;
  vector<vector<point> > m;
  while(cin >> n && n!=-1){ 
    vector<point> t(n);
    double a,b;
    for(int i=0;i<n;++i){
      cin >> a >> b;
      t[i]=point(a,b);
    }
    vector<point> r;
    m.push_back(r);
    convexHull(t,*(--m.end()));
  }
  double a,b;
  vector<bool> touch(m.size(),false);
  while(cin >> a >> b){
    point p(a,b);
    for(int i=0;i<int(m.size());++i)
      if(isInside(p, m[i]))
	touch[i]=true;
  }
  double res=0;
  for(int i=0;i<int(touch.size());++i)
    if(touch[i])
      res+=computeArea(m[i]);

  cout << fixed << setprecision(2) << res << '\n';
}
