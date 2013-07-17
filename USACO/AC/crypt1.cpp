/*
ID: blabla41
PROG: crypt1
LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int N;
bool tab[10];

bool valid(int n){
  if (n>0){
    return tab[n%10] && valid(n/10);
  }
  return true;
}

int main(){
  ofstream fout ("crypt1.out");
  ifstream fin ("crypt1.in");
  
  for(int i=0;i<10;++i) tab[i]=false;
  fin >> N;
  int tmp;
  for(int i=0;i<N;++i){
    fin >> tmp;
    tab[tmp]=true;
  }

  int res=0;
  for(int i=111;i<1000;++i)
    for(int j=11;j<100;++j)
      if (valid(i) && valid(j) && (i*(j%10))/1000==0 && valid(i*(j%10)) && (i*(j/10))/1000==0 && valid(i*(j/10)) && (i*j)/10000==0 && valid(i*j)){
	++res;
	//cout << i << ' ' << j << '\n';
}
    
  fout << res << '\n';
}
