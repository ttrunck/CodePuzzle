#include<iostream>
#include<cmath>

using namespace std;

int const N=1000000;

bool is_square(int n){
  int tmp=sqrt(n);
  return tmp*tmp==n;
}

bool ok(int a, int b, int c){
  return is_square(a*a+(b+c)*(b+c));
}

int main(){
  int res=0;
  for(int a=1;a<=N;++a){
    for(int b=a;b>0;--b)
      for(int c=b;c>0;--c)
	if(ok(a,b,c)) ++res;
    //cout << a << ' ' << res << '\n';
    if(res>N){
      cout << a << '\n';
      return 0;
    }
  }
}
