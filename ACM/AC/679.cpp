#include<iostream>

using namespace std;

int pow(int n){
  int res=1;
  for(int i=0;i<n;++i)
    res*=2;
  return res;
}

int aux(int d, int l){
  int res=0;
  for(int i=d;i>0;--i){
    if(l%2==0)
      res+=pow(i-2);
    else
      res+=pow(i-1);
    l/=2;
  }
  return res;
}


int main(){
  int cas;
  cin >> cas;
  while(cas--){
    int d, l;
    cin >> d >> l;
    cout << aux(d,l-1) << endl;
  }
}
