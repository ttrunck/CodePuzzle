#include<iostream>
#include<vector>

using namespace std;

int fact(int i){
  if(i==0) return 1;
  return i*fact(i-1);
}

int next(int n){
  int res=0;
  while(n!=0){
    res+=fact(n%10);
    n/=10;
  }
  return res;
}

int nb(vector<int> tab, int elt){
  int i=0;
  while(i<tab.size() && tab[i]!=elt)++i;
  if(i==tab.size())return -1;
  else return i;
}

int seq(int n){
  vector<int> tab;
  while(nb(tab, n)==-1){
    tab.push_back(n);
    n=next(n);
  }
  return tab.size();
}

int main(){
  int res=0;
  for(int i=1;i<1000000;++i)
    if(seq(i)==60) res++;

  cout << res << '\n';
}
