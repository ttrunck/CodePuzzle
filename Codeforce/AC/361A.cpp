#include<iostream>

using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  for(int i=0;i<n;++i){
    for(int j=0;j<n;++j)
      if(i==j)
	cout << k << ((j==n-1)?'\n':' ');
      else
	cout << 0 << ((j==n-1)?'\n':' ');
  }
}
