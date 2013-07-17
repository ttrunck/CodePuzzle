/*
ID: blabla41
PROG: concom
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

ofstream fout ("concom.out");
ifstream fin ("concom.in");

int N;
int tab[102][102];
bool contr[102][102]; 

int main(){
  fin >> N;
  for(int i=0;i<=100;++i)
    for(int j=0;j<=100;++j){
      tab[i][j]=0;
      contr[i][j]=false;
    }

  int a,b;
  for(int i=0;i<N;++i){
    fin >> a >> b;
    fin >> tab[a][b];
  }


  for(int i=1;i<=100;++i){
    bool cont=true;
    contr[i][i]=true;
    int tmp=0;
    while(cont){
      cont=false;
      for(int j=1;j<=100;++j){
	if(!contr[i][j]){
	  tmp=0;
	  for(int k=1;k<=100;++k)
	    if(contr[i][k])
	      tmp+= tab[k][j];
	  if (tmp>50){
	    contr[i][j]=true;
	    cont=true;
	  }
	}
      }
    }
  }

  // for(int i=0;i<10;++i){
  //   for(int j=0;j<10;++j)
  //     cout << tab[i][j] << ' ';
  //   cout << '\n';
  // }

  // cout << "ZOUBON\n";

  // for(int i=0;i<10;++i){
  //   for(int j=0;j<10;++j)
  //     cout << contr[i][j] << ' ';
  //   cout << '\n';
  // }


  for(int i=1;i<=100;++i)
    for(int j=1;j<=100;++j)
      if (i!=j && contr[i][j])
	fout << i << ' ' << j << '\n';
}
