#include<iostream>
#include<string>
#include<map>

typedef long long ll;

using namespace std;

map<string, ll> mem;

string s = "100001000101100101010001011000010100000000010100100001001010000000000000000000000000";
string ss = "1010";

ll aux(string& s){
  if(mem.find(s)!=end(mem)) return mem[s];
  ll res=0;
  int i=0;
  while(i<int(s.size()) && s[i]=='0')++i;
  if(i==int(s.size())) return mem[s]=1;
  s[i]='0';
  res+=aux(s);
  int j=i+1;
  while(j<int(s.size()) && s[j]=='1')++j;
  if(j<int(s.size())){
    for(int k=i;k<j;++k)
      s[k]='0';
    s[j]='1';
     res += aux(s);
    for(int k=i;k<j;++k)
      s[k]='1';
    s[j]='0';
  }

  s[i]='1';

  return mem[s]=res;
}

int main(){
  cout << aux(s) << endl;
}
