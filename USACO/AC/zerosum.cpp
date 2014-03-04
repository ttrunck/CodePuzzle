/*
ID: blabla41
PROG: zerosum
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

ofstream fout ("zerosum.out");
ifstream fin ("zerosum.in");

int N;
int tab[10];
int compt[10];

bool plusun(){
  // for(int i=0;i<N;++i){
  //   cout << tab[i] << ' ';
  // }
  // cout << endl;

  compt[0]++;
  for(int i=0;i<N-1;++i){
    if(compt[i]==3){
      compt[i]=0;
      compt[i+1]++;
    }
  }
  for(int i=0;i<N-1;++i){
    if (compt[i]==2)
      tab[N-2-i]=1;
    else if(compt[i]==1)
      tab[N-2-i]=0;
    else
      tab[N-2-i]=2;
  }
  return (compt[N-1]==0);
}

int calc(){
  int curr=0, tmp=1, plus=true;
  for(int i=0;i<N-1;++i){
    if(tab[i]==0){
      curr+= plus?tmp:-tmp;
      tmp=i+2;
      plus=true;
    }
    if(tab[i]==1){
      curr+= plus?tmp:-tmp;
      tmp=i+2;
      plus=false;
    }
    if(tab[i]==2)
      tmp= 10*tmp+i+2;
  }
  curr+= plus?tmp:-tmp;
  //  cout << curr << endl;
  return curr;
}

void print(){
  fout << 1;
  for(int i=2;i<=N;++i){
    if (tab[i-2]==0) fout << '+' << i;
    else if (tab[i-2]==1) fout << '-' << i;
    else fout << ' ' << i;
  }
  fout << '\n';
}

int main(){
  fin >> N;
  while(plusun()){
    if (calc()==0){
      print();
      //  fout << '=' << calc() << '\n';
    }
  }
}
