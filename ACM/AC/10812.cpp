#include<iostream>

using namespace std;

int main(){
  int n=0;
  cin >> n;
  while(n--){
    int a, b;
    cin >> a >> b;
    int x=(a+b)/2;
    int y=(a-b)/2;
    if(y<0 || x+y != a || x-y !=b) cout << "impossible" << endl;
    else cout << x << ' ' << y << endl;
  }
}
