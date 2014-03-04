/*
ID: blabla41
PROG: holstein
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

ofstream fout ("holstein.out");
ifstream fin ("holstein.in");
  
bool f(int a, int b){
    
int ta=a,tb=b;
  int na=0,nb=0;
  while(ta!=0){
    if (ta%2==1) na++;
    ta/=2;
  }
  while(tb!=0){
    if (tb%2==1) nb++;
    tb/=2;
  }
  if (na!=nb) return na<nb;
  return b>a;
}

int V;
int obj[30];
int tab[20][30];
int N;
int ordre[35000];
int check[30];

bool verif(int K){
  for (int i=0;i<V;++i)
    check[i]=0;
  int compt=0;
  while(K!=0){
    if (K%2==1){
      for(int i=0;i<V;++i)
	check[i]+=tab[compt][i];
    }
    compt++;
    K/=2;
  }
  for(int i=0;i<V;++i)
    if(check[i]<obj[i]) return false;
  return true;
}

void aff(int i){
  int ti=i;
  int compt=0;
  while(ti!=0){
    if (ti%2==1){
      ++compt;
    }
    ti/=2;
  }
  fout << compt;
  compt=0;
  while(i!=0){
    if (i%2==1){
      fout << ' ' << compt+1;
    }
    ++compt;
    i/=2;
  }
  fout << '\n';
}

int main(){
  fin >> V;
  for(int i=0;i<V;++i)
    fin >> obj[i];
  fin >> N;
  for(int i=0;i<N;++i)
    for(int j=0;j<V;++j)
      fin >> tab[i][j];
  
  int paf=1<<N;

  for(int i=0;i<paf;++i)
    ordre[i]=i;
  stable_sort(ordre,ordre+paf,f);
  
  int i;
  while(1){
    // cout << ordre[i] << '\n';
    if (verif(ordre[i])) break;
      ++i;
  }

  aff(ordre[i]);

}
