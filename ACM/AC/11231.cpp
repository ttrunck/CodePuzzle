#include<iostream>
#include<cmath>

using namespace std;

int compt(int n){
  return (2*(n/2)-6)/2;
}

long long aux(int n, int m, int c){
  if(n<8 || m<8) return 0;
  if(c==1){
    return aux(n-1,m,0)+(n>=8?compt(m):0);
  }
  else{
    return aux(n-1,m,1)+(n>=8?compt(m-1):0);
  }
}

int main(){
  int n,m,c;
    while(cin >> n >> m >> c && (n||m||c)){
      cout << aux(n,m,c) << '\n';
    }
}
