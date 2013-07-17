#include<iostream>
#include<gmpxx.h>

using namespace std;

typedef mpz_class ent;

bool aux(ent res, ent r, ent t){
  return (res)*(2*r+1)+2*res*(res-1)<=t;
}

int main(){
  int nbcase;
  cin >> nbcase;
  for(int icase=1;icase<=nbcase;++icase){
    cout << "Case #" << icase << ": ";
    ent r, t;
    cin >> r >> t;
    ent lo=0, hi=t;
    while(lo!=hi){
      ent x=(lo+hi)/2;
      if(aux(x,r,t))
	lo=x+1;
      else
	hi=x;
    }
    cout << lo-1 << endl;
  }
}
