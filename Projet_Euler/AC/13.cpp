#include <iostream>
#include <gmpxx.h>
#include <string>

using namespace std;

typedef mpz_class ent;

int main(){
  ent res=0;
  ent tmp;
  while(cin >> tmp){
    res+=tmp;
  }
  cout << res << '\n';;

}
