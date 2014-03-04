#include<iostream>

using namespace std;

int const N=50;

bool is_right(int x1, int y1, int x2, int y2){
  if(x1==y1 && x1==0) return false;
  if(x2==y2 && x2==0) return false;
  int d1=x1*x1+y1*y1;
  int d2=x2*x2+y2*y2;
  int d=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
  if (d==d1+d2|d1==d+d2|d2==d+d1){
    //cout << x1 << ',' << y1 << ' ' << x2 << ',' << y2 << '\n';
    return true;
  }
  return false;
}

int main(){
  int res=0;
  for(int x1=0;x1<=N;++x1)
    for(int y1=0;y1<=N;++y1){
      for(int y2=y1+1;y2<=N;++y2)
	if(is_right(x1,y1,x1,y2)) ++res;
      for(int x2=x1+1;x2<=N;++x2)
	for(int y2=0;y2<=N;++y2)
	  if(is_right(x1,y1,x2,y2)) ++res;
    }
  cout << res << '\n';
}
