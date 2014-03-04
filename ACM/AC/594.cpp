#include<iostream>

using namespace std;



int conv(int n){
  int res=0;
  for(int i=0;i<4;++i){
    res<<=8;
    res+=n&255;
    n>>=8;
  }
  return res;
}

int main(){
  int n;
  while(cin >> n)
    cout << n << " converts to " << conv(n) << endl;
}
