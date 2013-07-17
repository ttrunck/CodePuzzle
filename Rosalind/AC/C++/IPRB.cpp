#include<iostream>
#include<string>

using namespace std;

int main(){
  double k,m,n;
  cin >> k >> m >> n;
  double nn=k+m+n;
  cout << k/nn+(m/nn)*0.5+(m/nn)*0.5*(k/(nn-1)+(m-1)/(nn-1)*0.5)+n/nn*(k/(nn-1)+m/(nn-1)*0.5) << endl;
}
