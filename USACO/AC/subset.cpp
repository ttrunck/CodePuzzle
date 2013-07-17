/*
ID: blabla41
PROG: subset
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

ofstream fout ("subset.out");
ifstream fin ("subset.in");

const int MAX=1000;
long long tab[MAX][50];
int N;
bool mem[MAX][50];

long long f(int a, int b){
  //cout << a << ' ' << b << endl;
  
  if (a==0) return 1;
  if (a<0 || b<0) return 0;
  
  if (mem[a][b]) return tab[a][b];
  else{
    tab[a][b]= f(a,b-1)+ f(a-b,b-1);
    mem[a][b]=true;
    return tab[a][b];
  }
}


int main(){
  fin >> N;

 
    for(int j=0;j<50;++j)
      for(int i=0;i<MAX;++i){
	mem[i][j]=false;
	tab[i][j]=0;
      }

    if (((N*(N+1)) % 4) !=0)
      fout << 0 << endl;
    else
      fout << f((N*(N+1))/4,N)/2 << endl;
    
}
  
