#include<iostream>

using namespace std;

int aux(int n){
  if(n==0) return 1;
  if(n%2==1) return 0;
  int res=0;
  for(int i=1;i<=n;++i){
    res+=aux(i-1)*aux(n-i-1);
  }

  return res;
}

int main(){
  bool first=true;
  int n;
  while(cin >> n){
    if(!first)
      cout << '\n';
    first=false;
    cout << aux(2*n) << '\n';
  }

}
