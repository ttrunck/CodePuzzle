#include <iostream>
#include <cmath>
using namespace std;

int const N=20;

int tab[N][N];

int main(){
  for(int i=0;i<N;++i)
    for(int j=0;j<N;++j)
      cin >> tab[i][j];

  int maxi=0;
  for(int i=0;i<N;++i)
    for(int j=0;j<N-4;++j)
      maxi=max(maxi,tab[i][j]*tab[i][j+1]*tab[i][j+2]*tab[i][j+3]);

for(int i=0;i<N-4;++i)
    for(int j=0;j<N;++j)
      maxi=max(maxi,tab[i][j]*tab[i+1][j]*tab[i+2][j]*tab[i+3][j]);

for(int i=0;i<N-4;++i)
    for(int j=0;j<N-4;++j)
      maxi=max(maxi,tab[i][j]*tab[i+1][j+1]*tab[i+2][j+2]*tab[i+3][j+3]);

for(int i=N-1;i>3;--i)
    for(int j=0;j<N-4;++j)
      maxi=max(maxi,tab[i][j]*tab[i-1][j+1]*tab[i-2][j+2]*tab[i-3][j+3]);

 cout << maxi << '\n';
}
