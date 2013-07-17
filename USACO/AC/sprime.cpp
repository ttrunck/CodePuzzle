/*
ID: blabla41
PROG: sprime
LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

bool prime(int i){
  if (i==2) return true;
  if (i%2==0) return false;
  int k=3;
  while(k<=sqrt(i)){
    if (i%k==0) return false;
    k+=2;
  }
  return true;
}

vector<int> tab[9];
int N;

int main(){
  ofstream fout ("sprime.out");
  ifstream fin ("sprime.in");
  fin >> N;
  tab[1].push_back(2);
  tab[1].push_back(3);
  tab[1].push_back(5);
  tab[1].push_back(7);
  for(int i=2;i<=N;++i){
    for(int j=0;j<tab[i-1].size();++j){
      if (prime(tab[i-1][j]*10+1))
	tab[i].push_back(tab[i-1][j]*10+1);
      if (prime(tab[i-1][j]*10+3))
	tab[i].push_back(tab[i-1][j]*10+3);
      if (prime(tab[i-1][j]*10+7))
	tab[i].push_back(tab[i-1][j]*10+7);
      if (prime(tab[i-1][j]*10+9))
	tab[i].push_back(tab[i-1][j]*10+9);
    }
  }

  for(int j=0;j<tab[N].size();++j)
    fout << tab[N][j] << '\n';

}
