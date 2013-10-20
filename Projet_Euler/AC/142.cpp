#include<iostream>
#include<cmath>

using namespace std;

int const N=1100000;

bool isSquare(int n){
  int tmp=sqrt(n);
  return tmp*tmp==n;
}

int main(){
  int res=3*N;

  for(int z=1;z<N;++z)
    for(int y=z+1, i=2;y<N;y=z+i*i, ++i)
      if(isSquare(y+z)){
	for(int x=y+1, j=2;x<N;x=y+j*j, ++j)
	  if(isSquare(x+y) && isSquare(x-z) && isSquare(x+z))
	    res=min(x+y+z, res);
      }

  if(res!=3*N)
    cout << res << endl;
}
