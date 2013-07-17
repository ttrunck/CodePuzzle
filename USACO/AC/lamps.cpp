/*
ID: blabla41
PROG: lamps
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

ofstream fout ("lamps.out");
ifstream fin ("lamps.in");

int N;
int C;
int known[101];
vector <vector <int> > res;

bool eq_vect(vector<int> a, vector<int> b){
  if (a.size()!=b.size()) return false;
  for(int i=0;i<a.size();++i)
    if(a[i]!=b[i]) return false;
  return true;
}

bool comp_vect(vector<int> a, vector<int> b){
  if (a.size()!=b.size()) return false;
  for(int i=0;i<a.size();++i){
    if(a[i]>b[i]) return false;
    if(a[i]<b[i]) return true;
  }
  return true;
}

void is_ok(int cas){
  vector<int> tmp(N);
  for(int i=0;i<N;++i)
    tmp[i]=1;
  
  if(cas%2==1){
    for(int i=0;i<N;++i)
      tmp[i]= 1-tmp[i];
  }

  if((cas)/2%2==1){
    for(int i=0;i<N;i+=2)
      tmp[i]= 1-tmp[i];
  }

  if((cas)/4%2==1){
    for(int i=1;i<N;i+=2)
      tmp[i]= 1-tmp[i];
  }

  if((cas/8)%2==1){
    for(int i=0;i<N;i+=3)
      tmp[i]= 1-tmp[i];
  }

  for(int i=0;i<N;++i){
    if(known[i]!=-1 && known[i]!= tmp[i])
      return;
  }
  res.push_back(tmp);
}

int main(){
  fin >> N >> C;
  for(int i=0;i<N;++i)
    known[i]= -1;
  int tmp;
  fin >> tmp;
  while(tmp!=-1){
    known[tmp-1]= 1;
    fin >> tmp;
  }
  fin >> tmp;
  while(tmp!=-1){
    known[tmp-1]= 0;
    fin >> tmp;
  }
  
  if(C==0){
    is_ok(0);
  }

  if(C==1){
    is_ok(1);
    is_ok(2);
    is_ok(4);
    is_ok(8);
  }

  if(C==2){
    is_ok(3);
    is_ok(5);
    is_ok(9);
    is_ok(6);
    is_ok(10);
    is_ok(12);
  }

  if(C==3){
    is_ok(1);
    is_ok(2);
    is_ok(4);
    is_ok(8);    
    is_ok(7);
    is_ok(11);
    is_ok(13);
    is_ok(14);
  }


  if (C>3){
  for(int i=0;i<15;++i)
    is_ok(i);
  }

  sort(res.begin(), res.end(), comp_vect);
  vector< vector<int> >::iterator it;
  it=unique(res.begin(), res.end(), eq_vect);
  res.resize(it - res.begin());
  

  for(int i=0;i<res.size();++i){
    for(int j=0;j<N;++j)
      fout << res[i][j];
    fout << endl;
  }
  if (res.size()==0)
    fout << "IMPOSSIBLE\n";
}
