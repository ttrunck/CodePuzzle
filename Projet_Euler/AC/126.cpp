#include<iostream>
#include<vector>

using namespace std;

const int N=1000;
const int C=100000;

typedef long long ll;

ll cubic(ll x, ll y, ll z, ll n){
  return 2*(x*y+x*z+y*z) + 4*(x+y+z+n-2)*(n-1);
}

int main(){
  
  vector<int> c(C);

  for(ll x=1;x<C;++x)
    for(ll y=x;x*y<C;++y)
      for(ll z=y;cubic(x,y,z,1)<C;++z)
	for(ll n=1;cubic(x,y,z,n)<C;++n)
	  c[cubic(x,y,z,n)]++;

  for(int i=0;i<C;++i)
    if(c[i]==N){
      cout << i << endl;
      break;
    }
      
}
