#include<iostream>

using namespace std;

const int N=1000000;

int lamina(int trou, int tilde){
  int res=0;
  int size=trou;
  int usetilde=0;
  while(usetilde+4*(size+1)<=tilde){
    usetilde=usetilde+4*(size+1);
    size+=2;
    res++;
  }
  return res;
}

int main(){

  int res=0;
  for(int i=1;i<N/2;++i)
    res+=lamina(i,N);
  cout << res << endl;
}
