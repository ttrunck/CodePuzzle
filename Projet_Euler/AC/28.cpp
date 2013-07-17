#include <iostream>
#include <cmath>

using namespace std;

int const N=1001;

int main(){
  int res=1, curr=1;
  for(int rg=2;rg<N;rg+=2)
    for(int i=0;i<4;++i)
      {
	curr+=rg;
	res+=curr;
      }

  cout << res << '\n';
  
}
