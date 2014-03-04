#include<iostream>
#include<gmpxx.h>
#include<algorithm>
#include<vector>
using namespace std;

typedef mpz_class ent;

int const N=100;

vector<ent> tab;

ent power(ent a,ent b){
  ent res=1;
  for(ent i=0;i<b;++i)
    res*=a;
  return res;
}

int main(){
  for(int a=2;a<=N;++a)
    for(int b=2;b<=N;++b)
      tab.push_back(power(a,b));
  
  vector<ent>::iterator it;
  sort(tab.begin(),tab.end());
  it=unique(tab.begin(),tab.end());
  tab.resize(it-tab.begin());
  cout << tab.size() << '\n';
  /*
  for(int i=0;i<tab.size();++i)
    cout << tab[i] << ' ';
  cout << '\n';
  */
}
