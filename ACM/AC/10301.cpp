#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

struct ring{
  double x,y,r;
  ring(double xx=0,double yy=0, double rr=0):x(xx),y(yy),r(rr){};
};

bool intersect(const ring & r1, const ring & r2){
  double dist=sqrt((r1.x-r2.x)*(r1.x-r2.x)+(r1.y-r2.y)*(r1.y-r2.y));
  return (r1.r+r2.r>dist
	  && abs(r1.r-r2.r)<dist
	  );
}

int find(int n, vector<int> & p){
  if(p[n]==n) return n;
  int tmp=find(p[n],p);
  return p[n]=tmp;
}

int main(){
  int n;
  while(cin >> n && n!=-1){
    vector<ring> t(n);
    for(int i=0;i<n;++i)   
      cin >> t[i].x >> t[i].y >> t[i].r;

    vector<int> p(n);
    for(int i=0;i<n;++i)
      p[i]=i;

    for(int i=0;i<n;++i){
      int tmp=find(i,p);
      for(int j=i+1;j<n;++j)
	if(intersect(t[i], t[j])){
	  //cerr << i << ' ' << j << " s'intersectent\n";
	  p[find(j,p)]=tmp;
	}
    }

    vector<int> res(n);
    for(int i=0;i<n;++i)
      res[find(i,p)]++;

    int maxi=0;
    for(int i=0;i<n;++i)
      maxi=max(maxi, res[i]);
    
    if(maxi!=1)
      cout << "The largest component contains " << maxi << " rings.\n";
    else
       cout << "The largest component contains " << maxi << " ring.\n";
  }
}
