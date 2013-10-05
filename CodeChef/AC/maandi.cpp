#include<iostream>

using namespace std;

bool overlucky(int n){
  while(n){
    if(n%10==7 || n%10==4)
      return true;
    n/=10;
  }
  return false;
}

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int res=0;
    
    for(int i=1;i*i<=n;++i)
      if(n%i==0){
	if(overlucky(i))
	  ++res;
	if(n/i!=i && overlucky(n/i))
	  ++res;
      }

    cout << res << '\n';
  }
}
