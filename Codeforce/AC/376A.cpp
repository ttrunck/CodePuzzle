#include<iostream>
#include<string>

using namespace std;

typedef long long ll;

int main(){
  string s;
  cin >> s;
  
  int pos=0;
  while(s[pos]!='^')++pos;
  
  ll left=0;
  for(int i=0;i<pos;++i)
    if(s[i]!='=')
      left+=(s[i]-'0')*(pos-i);

  ll right=0;
  for(int i=pos+1;i<int(s.size());++i)
    if(s[i]!='=')
      right+=(s[i]-'0')*(i-pos);

  if(left==right)
    cout << "balance\n";
  else if(left<right)
    cout << "right\n";
  else
    cout << "left\n";

}
