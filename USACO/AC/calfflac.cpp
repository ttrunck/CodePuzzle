/*
ID: blabla41
PROG: calfflac
LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>


using namespace std;

int main(){
  ofstream fout ("calfflac.out");
  ifstream finstream ("calfflac.in");
  
  string tab;
  string tmp;
  int debmax, finmax;
  int taille_max=0;
  
  int deb,fin;
  int taille_curr;

  while(getline(finstream, tmp)){
    tab+= tmp;
    tab+= '\n';
  }

  for(int i=0;i<tab.size();++i){
    if (isalpha(tab[i])){
      
      deb=i-1;
      fin=i+1;
      taille_curr=1;
      while(fin<tab.size() && !isalpha(tab[fin])) fin++;
      while(deb>=0 && !isalpha(tab[deb])) deb--;
      while(toupper(tab[deb])==toupper(tab[fin])){
	taille_curr+=2;
	if (taille_curr>taille_max){
	  debmax=deb;
	  finmax=fin;
	  taille_max=taille_curr;
	}	
	fin++;
	deb--;
	while(fin<tab.size() && !isalpha(tab[fin])) fin++;
	while(deb>=0 && !isalpha(tab[deb])) deb--;
      }
      
      deb=i;
      fin=i+1;
      taille_curr=0;
      while(fin<tab.size() && !isalpha(tab[fin])) fin++;
      while(deb>=0 && !isalpha(tab[deb])) deb--;
      while(toupper(tab[deb])==toupper(tab[fin])){
	taille_curr+=2;
	if (taille_curr>taille_max){
	  debmax=deb;
	  finmax=fin;
	  taille_max=taille_curr;
	}	
	fin++;
	deb--;
	while(fin<tab.size() && !isalpha(tab[fin])) fin++;
	while(deb>=0 && !isalpha(tab[deb])) deb--;
      }
    }
  }
  fout << taille_max << '\n' << tab.substr(debmax,finmax-debmax+1) << '\n';
}
  
