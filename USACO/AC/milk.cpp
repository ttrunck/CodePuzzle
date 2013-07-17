/*
ID: blabla41
PROG: milk
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool f_sort(pair<int,int> a, pair<int,int> b){
  return a.first< b.first;
}

int main(){
  ofstream fout ("milk.out");
  ifstream fin ("milk.in");
  int N, M;
  int price=0;
  fin >> N >> M;
  vector< pair<int,int> > tab;
  pair<int,int> tmp;
  for(int i=0; i< M;++i){
    fin >> tmp.first >> tmp.second;
    tab.push_back(tmp);
  }
  
  sort(tab.begin(),tab.end(),f_sort);
  
  int i=0;
  while(N>0){
    if (N<= tab[i].second){
      price+= N*tab[i].first;
	N=0;
    }
    else{
      price+= tab[i].first*tab[i].second;
      N-= tab[i].second;
    }
    ++i;
  }
  
  fout << price << '\n';
}
