#include<iostream>
#include<iomanip>

using namespace std;

int main(){
  double bank;
  int retrait;
  cin >> retrait >> bank;
  if(retrait%5==0 && retrait+0.5 <= bank)
    cout << fixed << setprecision(2) << bank-retrait-0.5 << endl;
  else
    cout << fixed << setprecision(2) << bank << endl;
  
}
