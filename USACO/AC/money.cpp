/*
ID: blabla41
PROG: money
LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

ofstream fout ("money.out");
ifstream fin ("money.in");

int V, N;
int coin[25];
long long res[10000];

int main(){
  fin >> V >> N;
  for(int i=0;i<V;++i)
    fin >> coin[i];

  res[0]=1;
  for(int i=0;i<V;++i)
    for(int j=coin[i];j<=N;++j)
      res[j]+=res[j-coin[i]];

  fout << res[N] << endl;
}
