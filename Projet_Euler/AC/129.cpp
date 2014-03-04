#include<iostream>

using namespace std;

const int N=1000000;

int a(int n){
  if(n%2==0) return 0;
  if(n%5==0) return 0;
  int res=1;
  int curr=1;
  while(!(curr%n==0)){
    res++;
    curr=(curr*10+1)%n;
  }
  return res;
}

int naif(int n){
  int res=n;
  while(a(res)<n) ++res;
  return res;
}

int main(){
    cout << naif(N) << endl;
}
