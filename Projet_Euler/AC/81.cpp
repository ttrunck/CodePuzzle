#include <iostream>
#include <cmath>

using namespace std;

typedef long long ent;

int const N=80;
ent tab[N][N];

int main(){
  for(int i=0;i<N;++i)
    for(int j=0;j<N;++j)
      cin >> tab[i][j];

  for(int i=1;i<N;++i){
    tab[i][0]+=tab[i-1][0];
    tab[0][i]+=tab[0][i-1];
  }

  for(int i=1;i<N;++i)
    for(int j=1;j<N;++j)
      tab[i][j]+=min(tab[i-1][j],tab[i][j-1]);

	cout << tab[N-1][N-1] << '\n';
}
