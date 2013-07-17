#include<iostream>
#include<cmath>
using namespace std;

double H, U, D, F;

int main(){
  cin >> H >> U >> D >> F;
  while(H!=0){
    double curr=0;
    int day=0;
    while(curr<H || curr>=0){
      curr+=max(U-U*day*F/100,0.);
      day++;      
      if(curr>H){
	cout << "success on day " << day << endl;
	break;
      }
      curr-=D;
      if(curr<0){
	cout << "failure on day " << day << endl;
	break;
      }
    }  
    cin >> H >> U >> D >> F;
  }
}
