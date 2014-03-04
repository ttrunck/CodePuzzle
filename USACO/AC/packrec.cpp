/*
ID: blabla41
PROG: packrec 
LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector< pair<int,int> > tab;
vector< pair<int,int> > res;
int mini=100000;

void calcaux(int lar, int lon){
  if (lar>lon) swap(lar,lon);
    if (lar*lon<mini){
      mini=lar*lon;
      res.clear();
    }
    if (lar*lon==mini)
      res.push_back(make_pair(lar,lon));
}

void calc(){
  int a1=tab[0].first;
  int a2=tab[0].second;
  int b1=tab[1].first;
  int b2=tab[1].second;
  int c1=tab[2].first;
  int c2=tab[2].second;
  int d1=tab[3].first;
  int d2=tab[3].second;

 
  int lar,lon;
  
  //cas1
  lar =a1+b1+c1+d1;
  lon= max(max(a2,b2), max(c2,d2));
  calcaux(lar,lon);

  //cas2
  lar= max(a1, b1+c1+d1);
  lon= a2+max(b2, max(c2,d2));
  calcaux(lar,lon);
  
 //cas3
  lar= d1+max(a1, b1+c1);
  lon= max(a2+b2, max(a2+c2, d2));
  calcaux(lar,lon);
  
  //cas4
  lar= a1+d1+max(b1,c1);
  lon= max(a2,max(b2+c2,d2));
  calcaux(lar,lon);
  
 //cas5
  lar= c1+d1+max(a1,b1);
  lon= max(a2+b2,max(c2,d2));
  calcaux(lar,lon);
  
  //cas6
  if (b2>=a2 && c1+d1<= a1+b1){
    lar= max(a1+b1,  c1+b1);
    lon= max(a2+c2, b2+d2);
      }
  calcaux(lar,lon);
  
}

void rotate(int i){
  for (int j=0;j<4;++j){
    if (i%2==1)
      tab[j]= make_pair(tab[j].second, tab[j].first);
    i=i/2;
  }
}

int main(){
  ofstream fout ("packrec.out");
  ifstream fin ("packrec.in");
  
  int tmp1, tmp2;
  for (int i=0;i<4;++i){
    fin >> tmp1 >> tmp2;
    tab.push_back(make_pair(tmp1,tmp2));
  }

  int paf=0;
  sort(tab.begin(),tab.end());
  for(int i=0;i<16;++i){
      rotate(i);
      calc();
      rotate(i);
    }
  while(next_permutation(tab.begin(),tab.end())){
    for(int i=0;i<16;++i){
      rotate(i);
      calc();
      rotate(i);
    }
  }

  fout << mini << '\n';

  sort(res.begin(),res.end());
  pair<int,int> tmp=make_pair(-1,-1);
  for(int i=0;i<res.size();++i){
    if (res[i]!=tmp){
      tmp= res[i];
      fout << res[i].first << ' ' << res[i].second << '\n';
    }
  }

}
