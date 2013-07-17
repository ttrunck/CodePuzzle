/*
ID: blabla41
PROG: milk2
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector< pair<int,int> > tab;

bool f_sort(pair<int,int> i, pair<int,int> j){
  return i.first < j.first;
}

int main(){
  ofstream fout ("milk2.out");
  ifstream fin ("milk2.in");

  int N;
  pair<int,int> tmp;
  fin >> N;
  for(int i=0;i<N;++i){
    fin >> tmp.first >> tmp.second;
    tab.push_back(tmp);
  }
  sort(tab.begin(),tab.end(),f_sort);
  
  int start= tab[0].first, until=tab[0].second;
  int maxmilk=until-start, maxnonmilk=0;
  for(int i=0;i<N;++i){
    tmp=tab[i];
    if (tmp.first > until){
      maxmilk= max(maxmilk, until-start);
      maxnonmilk=max(maxnonmilk, tmp.first - until);
      start=tmp.first;
      until=tmp.second;
    }
    else{
      until=max(until, tmp.second);
    }
  }
  fout << maxmilk << ' ' << maxnonmilk << '\n';
}
