/*
ID: blabla41
PROG: milk3
LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int A,B,C;
bool tab[21][21][21];

void fill(int a, int b, int c){
  if (!tab[a][b][c]){
    tab[a][b][c]= true;
    fill(max(0,a-B+b), min(B, b+a), c);
    fill(max(0,a-C+c), b, min(C, c+a));
    fill(a, max(0,b-C+c), min(C, c+b));
    fill(min(A, a+b), max(0,b-A+a), c);
    fill(min(A, a+c), b, max(0,c-A+a));
    fill(a, min(B, b+c), max(0,c-B+b));
  }
}

int main(){
  ofstream fout ("milk3.out");
  ifstream fin ("milk3.in");
  
  fin >> A >> B >> C;

  for(int i=0;i<21;++i)
    for(int j=0;j<21;++j)
      for(int k=0;k<21;++k)
	tab[i][j][k]=false;
  
  fill(0,0,C);

  bool first= true;
  int j=0;
  bool paf;
  
  for (int i=0;i<21;++i){
    paf=true;
    j=0;
    while(j<21 && paf)
      {
	if (tab[0][j][i]){
	  if (!first) fout << ' ';
	  fout << i;
	  first= false;
	  paf= false;
	}
	++j;
      }
  }
  fout << endl;
}
