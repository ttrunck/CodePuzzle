#include<iostream>
#include<cmath>
#include<vector>

typedef long long ent;

using namespace std;

ent const N=10000000000;

int m[10];
ent s[10];

bool prime(ent n){
  for(ent i=2;i<=sqrt(n);++i)
    if(n%i==0) return false;
  return true;
}

int count(ent n, int nb){
  int res=0;
  while(n!=0){
    if(n%10==nb) ++res;
    n/=10;
  }
  return res;
}

void aux(int nb){
  for(ent i=0;i<N;++i){
    int tmp=count(i,nb);
    if(tmp>m[nb]){
      if(prime(i)){
      m[nb]=tmp;
      s[nb]=i;
      }
    }
    else if(tmp==m[nb])
      if(prime(i))
	s[nb]+=i;
  }
}


int main(){
  for(int i=0;i<10;++i){
    m[i]=0;
    s[i]=0;
  }
 
  for(int nb=0;nb<10;++nb){
    aux(nb);
    cout << nb << ' ' << m[nb] << ' ' << s[nb]  << '\n';
  }

  ent res=0;
  for(int i=0;i<10;++i)
    res+=s[i];
  cout << res << '\n';
}
