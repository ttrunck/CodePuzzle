/*
ID: blabla41
PROG: ariprog
LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

bool bisquare[130000];
int N, M;
int MAXI;
int nbi[130000];

int main(){
  ofstream fout ("ariprog.out");
  ifstream fin ("ariprog.in");
  fin >> N >> M;
  MAXI= 2*M*M;
  for(int i=0;i<=MAXI;++i){
    bisquare[i]=false;
    nbi[i]=0;
  }
  for(int i=0;i<=M;++i)
    for(int j=0;j<=i;++j)
      bisquare[i*i+j*j]=true;

  int num=0;
  for(int i=0;i<MAXI;++i){
    if (bisquare[i]){
      num++;
      nbi[num]=i;
    }
  }

  bool paf;
  int taille;
  bool nosol=true;  
  int a;
  for(int b=1;(N-1)*b<=MAXI;b++){
    //if (b>10 && b%2==1) ++b;
    for(int i=1;i<num && nbi[i]+(N-1)*b<=MAXI;++i){
      a=nbi[i];
      
      for(taille=N-1;taille>0;--taille){
	//	if ((a+taille*b)>MAXI) break;
	if (!bisquare[a+taille*b]) break;
      }
      if (taille==0){
	nosol=false;
	fout << a << ' ' << b << '\n';
      }
    }
  }
  if (nosol)
    fout << "NONE\n";

}
