#include<iostream>

using namespace std;

int calc(int n, int m){
  int res=1;
  int C2=0, C5=0;
  for(int i=n-m+1;i<=n;++i){
    int j=i;
    while(j%2==0){
      j/=2;
      C2++;
    }
    while(j%5==0){
      j/=5;
      C5++;
    }
    res=(res*j)%10;
  }
  if(C5>C2){
    C5-=C2;
    C2=0;
  }
  else{
    C2-=C5;
    C5=0;
  }
  //cerr << res << ' ' << C2 << ' ' << C5 << '\n';
  for(int i=0;i<C2;++i)
    res=(res*2)%10;
  for(int i=0;i<C5;++i)
    res=(res*5)%10;

  return res;
}

int main(){
  int n, m;
  while(cin >> n >> m){
    cout << calc(n,m) << endl;
  }
}
