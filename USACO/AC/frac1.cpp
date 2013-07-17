/*
ID: blabla41
PROG: frac1
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

ofstream fout ("frac1.out");
ifstream fin ("frac1.in");
  
int gcd(int a,int b){
  if (a==0) return b;
  if (b==0) return a;
  return gcd(b,a%b);
}

vector<pair <int,int> > tab;

bool f(pair<int,int> a, pair<int,int> b){
  return a.first*b.second < a.second*b.first;
}

int main(){
  int N;
  int tmp;
  fin >> N;
  for(int i=1;i<=N;++i)
    for(int j=0;j<=i;++j){
    tmp= gcd(j,i);
    tab.push_back(make_pair(j/tmp,i/tmp));
    }
  sort(tab.begin(),tab.end(),f);
  pair<int,int> paf=make_pair(-1,-1);
  for(int i=0;i<tab.size();++i)
    if (tab[i]!=paf){
      paf=tab[i];
      fout << paf.first << '/' << paf.second << '\n';
    }
}
