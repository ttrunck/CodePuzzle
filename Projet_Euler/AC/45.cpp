#include<iostream>
#include<gmpxx.h>

using namespace std;

typedef mpz_class ent;

int main(){
  ent t=1, p=1, h=1;
  ent tk=1,pk=1,hk=1;
  int res=0;
  while(res<3){
    if(h==p && p==t){
      cout << t << '\n';
      tk++;
      t=tk*(tk+1)/2;
      res++;
    }
    if(h>p){
      pk++;
      p=pk*(3*pk-1)/2;
    }
    if(t>p){
      pk++;
      p=pk*(3*pk-1)/2;
    }
    if(p>t){
      tk++;
      t=tk*(tk+1)/2;
    }
    if(p>h){
      hk++;
      h=hk*(2*hk-1);
    }
  }
}
