#include<iostream>

using namespace std;

int main(){

  int n,k,l,r,sAll,sK;
  cin >> n >> k >> l >> r >> sAll >> sK; 

  for(int i=0;i<k;++i){
    int ek=sK/(k-i);
    sK-=ek;
    sAll-=ek;
    cout << ek << ' ';
  }

  for(int i=k;i<n;++i){
    int ek=sAll/(n-i);
    sAll-=ek;
    cout << ek << ' ';
  }

}
