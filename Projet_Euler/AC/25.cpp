#include <iostream>
#include <gmpxx.h>

using namespace std;

int main(){
  mpz_class a, b, c;
  
  a = 1;
  b = 1;
  for(int i=3;;++i){
    c=a+b;
    a=b;
    b=c;
    if(b.get_str(10).size()>=1000){
      cout << 'F' << i << " = " << b << '\n';
      return 0;
    }
  }
  
}
