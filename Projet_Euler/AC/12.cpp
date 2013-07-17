#include <iostream>
#include <cmath>

using namespace std;

int nb_div(int n){
  int res=0;
  for(int i=1;i<=n;++i)
    if(n%i==0) res++;
  return res;
}

int main(){
  int i;
  for(i=1;i<100000;++i){
    int nb;
    if(i%2==0)
      nb= nb_div(i/2)*nb_div(i-1);
    else
      nb= nb_div(i)*nb_div((i-1)/2);
    
    cout << (i*(i-1))/2 << ':' << nb << '\n';
    if (nb>500) break;

  }
  
  cout <<  (i*(i-1))/2 << '\n';
}
