#include<iostream>
#include<cmath>

using namespace std;

typedef long long ent;

ent const N=1500001;
int t[N];

ent gcd(ent a, ent b){
  if(b==0) return a;
  return gcd(b, a%b);
}

int main(){
  for(int i=0;i<N;++i)
    t[i]=0;
  for(ent m=1;m*m<=N;++m)
    for(ent n=1;n<m;++n){
      if(gcd(m,n)!=1) continue;
      ent a=m*m-n*n;
      if(a%2==0) continue;
      ent b=2*m*n;
      ent c=m*m+n*n;
      ent tmp=a+b+c;
      while(tmp<N){
	//cout << "tmp" << tmp << '\n';	
	t[tmp]++;
	tmp+=a+b+c;
	 
      }
    }
      int res=0;
      for(int i=0;i<N;++i)
	if(t[i]==1){
	  res++;
	  //cout << i << '\n';
	}      

      cout << res << '\n';
}
