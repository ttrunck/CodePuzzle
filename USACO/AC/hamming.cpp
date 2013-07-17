/*
ID: blabla41
PROG: hamming
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

ofstream fout ("hamming.out");
ifstream fin ("hamming.in");

int N,B,D;
vector<int> res;

int dist(int a,int b){
  int res=0;
  //cout << "dist " << a << ' ' << b;
  while (a!=0 || b!=0){
    if ((a%2)!=(b%2)) res++;
    a/=2;
    b/=2;
  }
  //cout << ' ' << res << '\n';
  return res;
}

bool valid(int k){
  for(int i=0;i<res.size();++i)
    if (dist(res[i], k)<D) return false;
  return true;
}

int main(){
  fin >> N >> B >> D; 

  int curr=1;
  int nb=1;
  res.push_back(0);
  while(nb!=N){
    if (valid(curr)){
      res.push_back(curr);
      nb++;
    }
    curr++;
  }
 
  fout << res[0];
  for(int i=1;i<res.size();++i){
    fout << ((i%10==0)?'\n':' ') << res[i]; 
  }
  fout << '\n';
}
