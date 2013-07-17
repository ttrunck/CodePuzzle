#include<iostream>
#include<cmath>

using namespace std;

typedef long long ent;

ent const N=100000000;

ent gcd(ent a, ent b){
  if(b==0) return a;
  return gcd(b, a%b);
}

int main(){
  int res=0;
  for(ent m=1;m*m<=N;++m)
    for(ent n=1;n<m;++n){
      if(gcd(m,n)!=1) continue;
      ent a=m*m-n*n;
      if(a%2==0) continue;
      ent b=2*m*n;
      ent c=m*m+n*n;
      if(a>b){
	ent tmp=a;
	a=b;
	b=tmp;
      }
      if(b-a==1)
	res+=N/(a+b+c);
    }
  cout << res <<'\n';
}
