#include <iostream>
#include <cmath>

using namespace std;

int const N=15;

int tab[N+2][N+2];

int main(){
  for(int i=0;i<N;++i)
    for(int j=0;j<=i;++j)
      cin >> tab[i][j];

  for(int i=N-1;i>=0;--i)
    for(int j=0;j<=i;++j){
      tab[i][j]+= max(tab[i+1][j], tab[i+1][j+1]);
    }
  cout << tab[0][0] << '\n';

}
