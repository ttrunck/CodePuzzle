#include<iostream>
#include<vector>
#include<utility>
#include<cmath>
#include<set>
#include<iomanip>

using namespace std;

const double epsi=0.0001;

inline double dist(const pair<int, int> & a, const pair<int, int> & b){
  return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

int find(vector<int> & p, int i){
  if(p[i]==i) return i;
  int tmp=find(p, p[i]);
  return p[i]=tmp;
}

void fusion(vector<int> & p, int i, int j){
  p[find(p,j)]=find(p,i);
}

int aux(double D, const vector<pair<int, int> > & t){
  int n=int(t.size());
  vector<int> p(n);
  for(int i=0;i<n;++i)
    p[i]=i;

  for(int i=0;i<n;++i)
    for(int j=i+1;j<n;++j)
      if(dist(t[i],t[j])<=D)
	fusion(p, i, j);

  set<int> s;
  for(int i=0;i<n;++i)
    s.insert(find(p, i));

  return int(s.size());
}

int main(){
  int cas;
  cin >> cas;
  while(cas--){
    int s, p;
    cin >> s >> p;
    
    vector<pair<int, int> > t(p);
    for(int i=0;i<p;++i)
      cin >> t[i].first >> t[i].second;

    double hi=100000000, lo=0;
    while(hi-lo>epsi){
      double x=(hi+lo)/2;
      if(aux(x,t)>s)
	lo=x;
      else
	hi=x;
      //   cerr << hi << ' ' << lo << endl;
    }
    
    

    cout << setprecision(2) << fixed << lo << '\n';

  }
}
