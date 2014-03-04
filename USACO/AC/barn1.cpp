/*
ID: blabla41
PROG: barn1
LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>


using namespace std;

vector< pair<int,int> > tab;

int main(){
  ofstream fout ("barn1.out");
  ifstream fin ("barn1.in");
  
  int M, S, C;
  int tmp;
  fin >> M >> S >> C;
  
  for(int i=0;i<C;++i){
    fin >> tmp;
    tab.push_back(make_pair(tmp,tmp));
  }

  sort(tab.begin(),tab.end());

  int mini;
  int indi;
  for(int K=C;K>M;--K){
     mini=10000;
    for(int i=0;i<tab.size()-1;++i){
      if (tab[i+1].first-tab[i].second<mini){
	mini=tab[i+1].first-tab[i].second;
	indi=i;
      }
    }
    tab[indi].second= tab[indi+1].second;
    tab.erase(tab.begin()+indi+1);
    //cout << "On contient\n";
    //for(int i=0;i<tab.size();++i){
    //cout << tab[i].first << ' ' << tab[i].second << '\n';
    //}
  }

  int res=0;
  for(int i=0;i<tab.size();++i){
    //  cout << tab[i].first << ' ' << tab[i].second << '\n';
    res+= 1+tab[i].second-tab[i].first;
  }
  fout << res << '\n';
}
