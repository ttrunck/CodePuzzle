#include <iostream>
#include <cmath>

using namespace std;

int tmp;

void count(long long i){
  tmp++;
  if (i<=0) cout << "What the fuck\n";
  if (i==1) return;
  if (i%2==0) return count (i/2);
  else return count(3*i+1);
}

int main(){
  int taille=0;
  int res=0;
  for(int i=1;i<1000000;i++){
    tmp=0;
    count(i);
    if(taille<tmp){
      taille=tmp;
      res=i;
    }
  }
  cout << res << '\n';
}
