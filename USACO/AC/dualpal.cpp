/*
ID: blabla41
PROG: dualpal
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool ispalindrome(string s){
  for(int i=0; i<s.size();++i)
    if (s[i]!=s[s.size()-1-i]) return false;
  return true;
}

string conver(int n){
  if (n==0) return "0";
  else if (n==1) return "1";
  else if (n==2) return "2";
  else if (n==3) return "3";
  else if (n==4) return "4";
  else if (n==5) return "5";
  else if (n==6) return "6";
  else if (n==7) return "7";
  else if (n==8) return "8";
  else if (n==9) return "9";
  else return "A";
}

string stringbase(int B, int n){
  if (n<B) return conver(n);
  else return stringbase(B, n/B).append(conver(n%B));
}

bool valid(int n){
  int nbres=0;
  for(int i=2;i<=10;++i)
    if (ispalindrome(stringbase(i,n))){
      nbres++;
      if (nbres>=2) return true;
    }
    return false;
}

int main(){
  ofstream fout ("dualpal.out");
  ifstream fin ("dualpal.in");
  int N, S;
  fin >> N >> S;
  S++;
  int nbres=0;
  while(nbres<N){
    if (valid(S)){
      nbres++;
      fout << S << '\n';
    }
    S++;
  }
}
