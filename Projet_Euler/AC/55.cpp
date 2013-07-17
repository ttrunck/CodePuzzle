#include<iostream>
#include<string>
#include<sstream>
#include<gmpxx.h>
typedef mpz_class ent;
using namespace std;

int const N=10000;

bool palindrome(ent n){
  ostringstream tmp;
  tmp << n;
  string s=tmp.str();
  for(int i=0;i<=s.size()/2;++i)
    if(s[i]!=s[s.size()-1-i]) return false;
  return true;
}

ent retourne(ent n){
  ostringstream tmp;
  tmp << n;
  string s=tmp.str();
  ent res=0;
  for(int i=s.size()-1;i>=0;--i)
    res= res*10+s[i]-'0';
  return res;
}

bool lychrel(int n){
  ent nn=n;
  for(int i=0;i<50;++i){
    // cout << retourne(nn) << ' ' << nn << '\n';
    nn+=retourne(nn);
    if(palindrome(nn)) return false;
  }
  return true;
}

int main(){
  int res=0;
  for(int i=0;i<N;++i)
    if(lychrel(i)){
      //cout << i << '\n';
      res++;
    }
  cout << res << '\n';
}
