#include<iostream>
#include<gmpxx.h>

using namespace std;

typedef mpz_class ent;

ent power(ent a,ent b){
  if(b==0) return 1;
  if(b==1) return a;
  ent tmp=power(a,b/2);
  return tmp*tmp*(b%2==0?1:a);
}

int main(){
  ent a, b;
  ent maxi=0;
  int line=0;
  int res_line=0;
  while(cin >> a >> b){
    cout << line++ << '\n';
    ent ab=power(a,b);
    if(ab>maxi){
      maxi=ab;
      res_line=line;
    }
  }
  cout << res_line << '\n';
}
