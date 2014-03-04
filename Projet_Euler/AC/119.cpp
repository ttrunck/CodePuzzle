#include<iostream>
#include<gmpxx.h>
#include<vector>
#include<algorithm>

typedef mpz_class ent;

using namespace std;

vector<ent> p;

int const B1=100;
int const B2=20;

ent power(ent a, ent b){
  if(b==0) return 1;
  ent tmp=power(a, b/2);
  if(b%2==0) return tmp*tmp;
  else return tmp*tmp*a;
}

void init(){
  for(ent i=0;i<B1;++i)
    for(ent j=0;j<B2;++j){
      ent tmp=power(i,j);
      if(tmp>9)
	p.push_back(power(i,j));
    }
  sort(p.begin(),p.end());
  p.resize(unique(p.begin(),p.end())-p.begin());
}

int main(){
  init();

  int k=1;
  int ii=0;
  
  while(k<=30 && ii<p.size()){
    ent i=p[ii];
    ++ii;
    int p=0;
    ent tmp=0;
    ent n=i;
    while(n!=0){
      tmp+=n%10;
      n/=10;
    }
    if(tmp==1) continue;
    while(power(tmp,p)<i)++p;
    if(power(tmp,p)==i){
      cout << k << ' ' << i << ' ' << p << ' ' << tmp << '\n';
      k++;
    }
  } 
}
