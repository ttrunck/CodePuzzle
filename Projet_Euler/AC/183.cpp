#include<iostream>
#include<cmath>

using namespace std;

typedef long long ll;

const int N=10000;
const double e=exp(1);


int gcd(int a, int b){
  if(b==0) return a;
  return gcd(b,a%b);
}

int find(double x){
  double t=x/e;
  int res=0;
  double maxi=0;
  for(int i=t;i<=t+1;++i){
    double tmp=i*log(x/i);
    if(tmp>maxi){
      maxi=tmp;
      res=i;
    }
  }
  return res;
}

bool terminate(int n){
  while(n%2==0)n/=2;
  while(n%5==0)n/=5;
  return n==1;
}

int main(){
  ll res=0;
  for(int i=5;i<=N;++i){
    int k=find(i);
    k/=gcd(i,k);
    if(!terminate(k))
      res+=i;
    else
      res-=i;
  }

  cout << res << '\n';
}
