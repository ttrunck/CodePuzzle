#include<iostream>

using namespace std;

int gcd(int a, int b){
  return b==0?a:gcd(b,a%b);
}

int main(){
  int nbcase;
  cin >> nbcase;
  while(nbcase--){
    int a,b;
    char trash;
    cin >> a >> trash >> b;
    while(a!=b){
      if(a<b){
	cout << 'L';
	int aa=b-a;
	int bb=a;
	int d=gcd(a,b);
	a=aa/d;
	b=bb/d;
      }
      else{
	cout << 'R';
	int aa=b;
	int bb=a-b;
	int d=gcd(a,b);
	a=aa/d;
	b=bb/d;
      }
    }
    cout << '\n';
  }
}
