/*
ID: blabla41
PROG: nocows
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

ofstream fout ("nocows.out");
ifstream fin ("nocows.in");

int mem[201][101];

int calc(int n,int k){

  if(mem[n][k]!=-1) return mem[n][k];
  
  if(k==1) return (n==1)?1:0;
  if (2*k-1>n) return 0;
  if(n%2==0) return 0;

  int res=0;
  for(int j=0;j<k-1;++j)
    for(int i=1;i<n-1;++i)
      res= (res+(calc(i,k-1)*calc(n-i-1,j)))%9901;
  
  res= 2*res;

  
  for(int i=1;i<n-1;++i)
     res= (res+(calc(i,k-1)*calc(n-i-1,k-1)))%9901;
  

  mem[n][k]= (res)%9901;

  //cout << n << ' ' << k << ' ' << res << '\n';

  return ((res)%9901);
}

int N,K;
int main(){
  fin >> N >> K;
  for(int i=0;i<=200;++i)
    for(int j=0;j<=100;++j)
      mem[i][j]=-1;

  fout << calc(N,K) << endl;
}
