/*
ID: blabla41
PROG: preface
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

ofstream fout ("preface.out");
ifstream fin ("preface.in");

int N;
int tab[7];

void pagerom(int n){
  if (n>=1000){
    tab[6]++;
    return pagerom(n-1000);
  }
if (n>=900){
    tab[6]++;
    tab[4]++;
    return pagerom(n-900);
  }
if (n>=500){
    tab[5]++;
    return pagerom(n-500);
  }
if (n>=400){
    tab[5]++;
    tab[4]++;
    return pagerom(n-400);
  }
if (n>=100){
    tab[4]++;
    return pagerom(n-100);
  }
if (n>=90){
    tab[4]++;
    tab[2]++;
    return pagerom(n-90);
  }
if (n>=50){
    tab[3]++;
    return pagerom(n-50);
  }
if (n>=40){
    tab[2]++;
    tab[3]++;
    return pagerom(n-40);
  }
if (n>=10){
    tab[2]++;
    return pagerom(n-10);
  }
if (n>=9){
    tab[2]++;
    tab[0]++;
    return pagerom(n-9);
  }
if (n>=5){
    tab[1]++;
    return pagerom(n-5);
  }
if (n>=4){
    tab[1]++;
    tab[0]++;
    return pagerom(n-4);
  }
if (n>=1){
    tab[0]++;
    return pagerom(n-1);
  }
}

int main(){
  fin >> N;
  
  for(int i=0;i<7;++i)
    tab[i]=0;
  
  for(int i=1;i<=N;++i)
    pagerom(i);

  if (tab[0]!=0)
    fout << 'I' << ' ' << tab[0] << '\n';
  if (tab[1]!=0) 
    fout << 'V' << ' ' << tab[1] << '\n';
  if (tab[2]!=0)
    fout << 'X' << ' ' << tab[2] << '\n';
  if (tab[3]!=0)
    fout << 'L' << ' ' << tab[3] << '\n';
  if (tab[4]!=0)
    fout << 'C' << ' ' << tab[4] << '\n';
  if (tab[5]!=0)
    fout << 'D' << ' ' << tab[5] << '\n';
  if (tab[6]!=0)
    fout << 'M' << ' ' << tab[6] << '\n';
}
