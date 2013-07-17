#include<iostream>
#include<cmath>

using namespace std;

typedef long long ent;

int main(){
  /*
  for(ent b=2;b<1000000000;b+=2){
    ent tmp=(5*b*b)/4+2*b+1;
    ent tmp1=sqrt(tmp);
    if(tmp1*tmp1==tmp)
      cout << b << ' ' << tmp1 << '\n';
    tmp-=4*b;
    tmp1=sqrt(tmp);
    if(tmp1*tmp1==tmp)
      cout << b << ' ' << tmp1 << '\n';
  }
  */
  ent n=1;
  ent res=0;
  for(ent m=1;m<100000000;++m){
    ent a=m*m-n*n;
      ent b=2*m*n;
      ent c=m*m+n*n;
      if(2*b+1==a){
	//cout << n << ' ' << m << ' ' << b << ' ' << a << ' ' << c << '\n'; 
	n=m;
	res+=c;
      }
      if(2*b-1==a){
	//cout << n << ' ' << m << ' ' << b << ' ' << a << ' ' << c << '\n'; 
	n=m;
	res+=c;
      }
  }
  cout << res << '\n';
}
