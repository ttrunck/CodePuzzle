#include<iostream>
#include<iomanip>

using namespace std;

int main(){
  double cow,car,show;
  while(cin >> cow >> car >> show){

    cout << fixed << setprecision(5) << car/(car+cow)*(car-1)/(car+cow-show-1)+cow/(car+cow)*car/(car+cow-show-1) << '\n';
  }
}
