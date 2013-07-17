#include<iostream>
#include<gmpxx.h>
#include<vector>

typedef mpz_class ent;

ent const N=1000000000;

using namespace std;

vector<ent> t;

void next(){
  t.push_back(t[t.size()-2]+t[t.size()-1]);
}

bool aux(ent nn){
  long n=nn.get_si();
  bool b[10];
  for(int i=1;i<10;++i)
    b[i]=false;
  for(int i=1;i<10;++i){
    b[n%10]=true;
    n/=10;
  }
  for(int i=1;i<10;++i)
    if(!b[i]) return false;
  return true;
}

bool pantadigit(ent n){
  if(!aux(n%N))return false;
  while(n>N) n/=10;
  return(aux(n));
}

int main(){
  t.push_back(1);
  t.push_back(1);
  t.push_back(1);
  while(!pantadigit(t[t.size()-1]))
    next();
  cout << t.size()-1 << '\n';
}
