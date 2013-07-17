/*
ID: blabla41
PROG: namenum
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool valid(string s, string n){
  if (s.size()!=n.size()) return false;
  for(int i=0;i<s.size();++i){
    if (s[i]=='Z' || s[i]=='Q') return false;
    if ((s[i]-'A'-((s[i]>'P')?1:0))/3+2!=n[i]-'0'){
      cout << s[i] << ' ' << n[i] << '\n';
      return false;
    }
  }
  return true;
}

int main(){
  ofstream fout ("namenum.out");
  ifstream fin ("namenum.in");
  ifstream din ("dict.txt");
  string tmp;
  string N;
  bool nbres=false;
  fin >> N;
  while (din >> tmp)
    if (valid(tmp,N)){
      fout << tmp << '\n';
      nbres=true;
    }
  if (!nbres) fout << "NONE\n";
}
