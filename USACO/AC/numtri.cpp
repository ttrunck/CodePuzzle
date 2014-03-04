/*
ID: blabla41
PROG: numtri
LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int tab[1001][1001];
int R;

int main(){
  ofstream fout ("numtri.out");
  ifstream fin ("numtri.in");
  fin >> R;
  for(int i=0;i<R;++i)
    for(int j=0;j<=i;++j)
      fin >> tab[i][j];

  for(int i=(R-2);i>=0;--i)
    for(int j=0; j<=i; ++j)
      tab[i][j]+=max(tab[i+1][j], tab[i+1][j+1]);

  fout << tab[0][0] << '\n';
}
