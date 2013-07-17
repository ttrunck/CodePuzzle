#include<iostream>

using namespace std;

bool panta(int x){
  int xx=x;
  bool t[9];
  for(int i=0;i<9;++i)
    t[i]=0;
  while(xx!=0){
    int tmp=xx%10;
    if(tmp==0) return false;
    tmp--;
    if(t[tmp]) return false;
    t[tmp]=true;
    xx/=10;
  }
  for(int i=0;i<9;++i)
    if(!t[i]) return false;
  return true;
}

int main(){
  for(int i=9000;i<10000;++i)
    if(panta(i*100000+2*i)) cout << i << 2*i << '\n';
}
