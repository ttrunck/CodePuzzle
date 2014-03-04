/*
ID: blabla41
PROG: checker
LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

#define NN 15

ofstream fout ("checker.out");
ifstream fin ("checker.in");

int N;
int res=0;
int pos[NN];
bool ligne[NN];
bool diag1[2*NN];
bool diag2[2*NN];

void place(int col){
  if (col==N){
    if (res<3){
      for(int i=0;i<N-1;++i)
	fout << pos[i]+1 << ' ';
      fout << pos[N-1]+1 << '\n';
    }
    res++;
  }
  for(int i=0;i<N;++i){
    if (!ligne[i] && !diag1[N-col+i] && !diag2[2*N-1-i-col]){
      pos[col]=i;
      ligne[i]=true;
      diag1[N-col+i]=true;
      diag2[2*N-1-i-col]=true;
      place(col+1);
      ligne[i]=false;
      diag1[N-col+i]=false;
      diag2[2*N-1-i-col]=false;
    }
  }

}

int main(){

  for(int i=0;i<NN;++i)
    ligne[i]=false;
  for(int i=0;i<2*NN;++i){
    diag1[i]=false;
    diag2[i]=false;
  }

  fin >> N;
  if (N<8)
    place(0);
  else{
    for(int i=0;i<N/2;++i){
      	pos[0]=i;
	ligne[i]=true;
	diag1[N+i]=true;
	diag2[2*N-1-i]=true;
	place(1);
	ligne[i]=false;
	diag1[N+i]=false;
	diag2[2*N-1-i]=false;
    }
    res*=2;
    if (N%2==1){
      int i=N/2;
      ligne[i]=true;
      diag1[N+i]=true;
      diag2[2*N-1-i]=true;
      place(1);
    }
    
     
  }
  fout << res << '\n';
}
