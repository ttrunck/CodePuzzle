#include<iostream>
#include<cmath>

using namespace std;

typedef long long ent;

ent const N=1000000000;

bool is_square(ent n){
  ent tmp=sqrt(n);
  return tmp*tmp==n;
}

int main(){
  ent res=0;
  for(ent n=2;3*n<=N;++n){
    ent tmp=3*n*n+2*n-1;
    if(is_square(tmp)){
      res+=3*n+1;
      cout << n << '\n';
	}
    tmp-=4*n;
    if(is_square(tmp)){
      res+=3*n-1;
      cout << n << '\n';
    }
  }

  cout << res << '\n';
}
