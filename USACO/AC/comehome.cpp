/*
ID: blabla41
PROG: comehome
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

ofstream fout ("comehome.out");
ifstream fin ("comehome.in");

const int maxi=1000000;
int tab[60][60];
int vu[60];

struct comp{
  bool operator()(int a, int b){
    return vu[a]>vu[b];
  }
};

priority_queue<int, vector<int>, comp> qu;

void dij(){
  int dep= qu.top();
  qu.pop();
  if (dep>30){
    char tmp= dep+'A';
    fout << tmp << ' ' << vu[dep] << endl;
    return;
  }

  for(int i=0;i<60;++i){
    

  }

}

int main(){
  int N, dist;
  char a, b;

  fin >> N;

  for(int i=0;i<60;++i)
    vu[i]=maxi;

  for(int i=0;i<60;++i)
    for(int j=0;j<60;++j)
      tab[i][j]=maxi;

  for(int i=0;i<N;++i){
    fin >> a >> b >> dist;
    tab[a-'A'][b-'A']= min(tab[a-'A'][b-'A'], dist);
    tab[b-'A'][a-'A']= tab[a-'A'][b-'A'];
  }

  vu[25]=0;
  qu.push(25);
  
  while(!qu.empty()){
    int dep= qu.top();
    qu.pop();
    if (dep<25){
      char tmp= dep+'A';
      fout << tmp << ' ' << vu[dep] << endl;
      return 0;
    }
    
    for(int i=0;i<60;++i){
      if (tab[dep][i]!=maxi && vu[i]>vu[dep]+tab[dep][i]){
	vu[i]= vu[dep]+tab[dep][i];
	qu.push(i);
      }
    } 
  }
}
