/*
ID: blabla41
PROG: gift1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main(){
  ofstream fout ("gift1.out");
  ifstream fin ("gift1.in");

  map<string,int> m;
  int nbpeople;
  string tmp,paf;
  int cash, share;
  string ordre[12];
  fin >> nbpeople;
  for(int i=0;i<nbpeople;++i){
    fin >> tmp;
    m[tmp]=0;
    ordre[i]= tmp;
  }

  while(fin >> tmp){
    fin >> cash >> share;
    for(int i=0;i<share;++i){
      fin >> paf;
      m[paf]+=cash/share;
	}
    if (share!=0) m[tmp]+= cash%share - cash;
  }

  for(int i=0;i<nbpeople;++i)
    fout << ordre[i] << ' ' << m[ordre[i]] << '\n';
}
