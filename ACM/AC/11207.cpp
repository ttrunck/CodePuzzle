#include<iostream>
#include<algorithm>

using namespace std;

inline double calc(int x, int y){
  return max(min(double(x),double(y)/4.), double(x)/2);
}

int main(){
  int n;
  while(cin >> n && n){
    int x,y;
    int res=0;
    double maxi=0;
    for(int i=1;i<=n;++i){
      cin >> x >> y;
      if(y<x) swap(x,y);
      double tmp=calc(x,y);
      if(tmp>maxi){
	  maxi=tmp;
	  res=i;
	}
    }
    cout << res << '\n';
  }
}
