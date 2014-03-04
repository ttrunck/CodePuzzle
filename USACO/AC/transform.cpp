/*
ID: blabla41
PROG: transform
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

string tab1[10];
string tab2[10];
int N;

bool rot270(){
  for(int i=0;i<N;++i)
    for(int j=0;j<N;++j)
      if (tab1[j][N-i-1]!=tab2[i][j]) return false;
  return true;
}

bool rot180(){
  for(int i=0;i<N;++i)
    for(int j=0;j<N;++j)
      if (tab1[N-i-1][N-j-1]!=tab2[i][j]) return false;
  return true;
}

bool rot90(){
  for(int i=0;i<N;++i)
    for(int j=0;j<N;++j)
      if (tab1[N-1-j][i]!=tab2[i][j]) return false;
  return true;
}

bool refl(){
  for(int i=0;i<N;++i)
    for(int j=0;j<N;++j)
      if (tab1[i][N-1-j]!=tab2[i][j]) return false;
  return true;
}

bool comb1(){
  for(int i=0;i<N;++i)
   for(int j=0;j<N;++j)
     if (tab1[N-1-i][j]!=tab2[i][j]) return false;
  return true;
}

bool comb2(){
  for(int i=0;i<N;++i)
   for(int j=0;j<N;++j)
      if (tab1[N-1-j][N-1-i]!=tab2[i][j]) return false;
  return true;
}

bool comb3(){
  for(int i=0;i<N;++i)
   for(int j=0;j<N;++j)
      if (tab1[j][i]!=tab2[i][j]) return false;
  return true;
}

bool comb(){
  return comb1()||comb2()||comb3();
}

bool nochan(){
  for(int i=0;i<N;++i)
    for(int j=0;j<N;++j)
      if (tab1[i][j]!=tab2[i][j]) return false;
  return true;
}

int main(){
  ofstream fout ("transform.out");
  ifstream fin ("transform.in");
  fin >> N;
  for(int i=0;i<N;++i)
    fin >> tab1[i];
  for(int i=0;i<N;++i)
    fin >> tab2[i];

  if (rot90()) fout << "1\n";
  else if (rot180()) fout << "2\n";
  else if (rot270()) fout << "3\n";
  else if (refl()) fout << "4\n";
  else if (comb()) fout << "5\n";
  else if (nochan()) fout << "6\n";
  else fout << "7\n";
}
