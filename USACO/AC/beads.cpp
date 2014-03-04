/*
ID: blabla41
PROG: beads
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

string necklace;

int score(int dep){
  int N=necklace.size();
  int res=0;
  
  char color=necklace[dep];
  for(int i=0;i<N;++i){
    if (necklace[(dep+i)%N]!='w' && necklace[(dep+i)%N]!= color) break;
    res++;
    if (color=='w') color=necklace[(dep+i+1)%N];
  }

  color=necklace[(dep+N-1)%N];
  for(int i=1;i<N;++i){
    if (necklace[(dep-i+N)%N]!='w' && necklace[(dep-i+N)%N]!= color) break;
    res++;
    if (color=='w') color=necklace[(dep-i-1+N)%N];
  }

  return min(res,(int) necklace.size());
}

int main(){
  ofstream fout ("beads.out");
  ifstream fin ("beads.in");
  int res=0;
  int pfff;
  fin >> pfff;
  fin >> necklace;
  for(int i=0;i<necklace.size();++i)
    res= max(res,score(i));
  fout << res << '\n';
}
