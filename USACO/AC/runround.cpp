/*
ID: blabla41
PROG: runround
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

ofstream fout ("runround.out");
ifstream fin ("runround.in");

int nombre[20];
int M;

bool isrunround(){
  int curs=0;
  bool touch[20];
  bool uniquenumber[10];
  for(int i=0;i<20;++i) touch[i]=false;
  for(int i=0;i<11;++i) uniquenumber[i]=false;
  while(nombre[curs+1]!=0) ++curs;
  int start=curs;
  
  for(int i=0;i<=start;++i){
    if (uniquenumber[nombre[i]]) return false;
    uniquenumber[nombre[i]]= true;
  }

  // cout << "unique test pass\n";
  //cout << "curs " << curs << '\n';
  curs= (curs-nombre[curs]+start+1)%(start+1);
  if(curs<0) curs+=start+1;
  touch[curs]=true;
  //cout << "curs " << curs << '\n';
  while(curs!= start){
    curs= (curs-nombre[curs]+start+1)%(start+1);
    if (curs<0)curs+=start+1;
    // cout << "curs " << curs << '\n';
    if(touch[curs]) return false;
    touch[curs]=true;
  }

  for(int i=0;i<=start;++i)
    if (!touch[i]) return false;

  return true;

}

void plusone(){
  int i=1;
  nombre[0]++;
  bool retenue= (nombre[0]==10);
  while(retenue){
    nombre[i-1]=1;
    nombre[i]++;
    retenue=(nombre[i]==10);
    i++;
  }
}

void init(int a){
  int i=0;
  while(a!=0){
    nombre[i]=a%10;
    if (nombre[i]==0) nombre[i]++;
    a=a/10;
    ++i;
  }
}

void print(){
  int i=0;
  while(nombre[i+1]!=0) ++i;
  long long res=nombre[i];
  --i;
  while(i>=0){
    res*=10;
    res+=nombre[i];
    --i;
  }
  fout << res;
}

int main(){
  fin >> M;
  init(M+1);
  //cout << isrunround(); 

  while(!isrunround())
    plusone();
  print();
  fout << endl;
}
