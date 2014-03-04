/*
ID: blabla41
PROG: palsquare
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
  else if (n==10) return "A";
  else if (n==11) return "B";
  else if (n==12) return "C";
  else if (n==13) return "D";
  else if (n==14) return "E";
  else if (n==15) return "F";
  else if (n==16) return "G";
  else if (n==17) return "H";
  else if (n==18) return "I";
  else if (n==19) return "J";
  else if (n==20) return "K";
  else return "L";
}

string stringbase(int B, int n){
  if (n<B) return conver(n);
  else return stringbase(B, n/B).append(conver(n%B));
}

int main(){
  ofstream fout ("palsquare.out");
  ifstream fin ("palsquare.in");
  
  int N;
  fin >> N;
  for(int i=1;i<=300;++i)
    if (ispalindrome(stringbase(N, i*i))) fout << stringbase(N, i) << ' ' << stringbase(N, i*i) << '\n';
}
