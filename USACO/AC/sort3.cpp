/*
ID: blabla41
PROG: sort3
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

ofstream fout ("sort3.out");
ifstream fin ("sort3.in");



int main(){
  int tab[1001];
  int N;
  fin >> N;
  for(int i=0;i<N;++i)
    fin >> tab[i];
  
  int n1=0,n2=0,n3=0;
  for(int i=0;i<N;++i){
    if (tab[i]==1) ++n1;
    if (tab[i]==2) ++n2;
    if (tab[i]==3) ++n3;
  }
  
  int n12=0,n13=0;
  for(int i=0;i<n1;++i){
    if (tab[i]==2) ++n12;
    if (tab[i]==3) ++n13;
  }

int n21=0,n23=0;
  for(int i=n1;i<n1+n2;++i){
    if (tab[i]==1) ++n21;
    if (tab[i]==3) ++n23;
  }

int n31=0,n32=0;
  for(int i=n1+n2;i<n1+n2+n3;++i){
    if (tab[i]==1) ++n31;
    if (tab[i]==2) ++n32;
  }
  //cout << n1 << ' ' << n2 << ' ' << n3 << '\n';
  //cout << n12 << ' ' << n13 << ' ' << n21 << ' ' << n23 << ' ' << n31 << ' ' << n32 << '\n';
  int tmp1=min(n12,n21);
  int tmp2=min(n13,n31);
  int tmp3=min(n23,n32);
  n12=max(0,n12-tmp1);
  n13=max(0,n13-tmp2);
  n21=max(0,n21-tmp1);
  n23=max(0,n23-tmp3);
  n31=max(0,n31-tmp2);
  n32=max(0,n32-tmp3);
  //  cout << tmp1 << ' ' << tmp2 << ' ' << tmp3 << '\n';
  //cout << n12 << ' ' << n13 << ' ' << n21 << ' ' << n23 << ' ' << n31 << ' ' << n32 << '\n';
 fout << tmp1+tmp2+tmp3+n12+n13+n21+n23<< '\n';

}
