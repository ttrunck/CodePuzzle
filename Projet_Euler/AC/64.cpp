#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

int gcd(int a,int b){
  if(b==0) return a;
  return gcd(b,a%b);
}

struct step{
  int a,b,c,d,n;
};

step f(step k){
  step kk;
  kk.n=k.n;
  kk.c=k.b*k.b*k.n-k.d*k.d;
  int tmp=gcd(k.c,kk.c);
  kk.a=k.c*(k.b*((int) sqrt(k.n))-k.d)/kk.c;
  kk.b=k.c*k.b/tmp;
  kk.d=(-k.c*k.d-kk.a*kk.c)/tmp;
  kk.c/=tmp;
 return kk;
}

void print(step k){
  cout << k.a << ' ' << k.b << ' ' << k.c << ' ' << k.d << ' ' << k.n << '\n';
}

bool operator==(step a, step b)
{
  return (a.a==b.a)&&(a.b==b.b)&&(a.c==b.c)&&(a.d==b.d)&&(a.n==b.n);
}

int nb_step(step k){
  //print(k);
  vector<step> t;
  int res=-1;
  while(! count(t.begin(),t.end(),k)>=1){
    t.push_back(k);
    k=f(k);
    res++;
  }
  return res;
}

step init(int n){
  step res;
  res.a=sqrt(n);
  res.b=1;
  res.c=1;
  res.d=-sqrt(n);
  res.n=n;
  return res;
}

int main(){
  int res=0;
  for(int i=2;i<=10000;++i){
    int tmp=sqrt(i);
    if(tmp*tmp==i) continue;
    if(nb_step(init(i))%2==1) res++;
  }
 cout << res << '\n';
}
