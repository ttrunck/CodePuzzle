#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int mod(const string& s){
  int mod=0;
  int curr=1;
  
  for(int i=int(s.size())-1;i>=0;--i){
    mod = (mod+(s[i]-'0')*curr) % 7;
    curr = (10*curr) % 7; 
  }
  return mod;
}

int mod(const vector<int>& t, int startT){
  int mod=0;
  int curr=startT;
  
  for(int i=int(t.size())-1;i>=0;--i){
    mod = (mod+(t[i])*curr) % 7;
    curr = (10*curr) % 7; 
  }
  return mod;
}

int main(){
  string s;
  cin >> s;

  int pos=0;
  while(s[pos]!='1') ++pos;
  swap(s[pos], s[0]);
  
  pos=0;
  while(s[pos]!='6') ++pos;
  swap(s[pos], s[1]);
  
  pos=0;
    while(s[pos]!='8') ++pos;
  swap(s[pos], s[2]);
  
  pos=0;
  while(s[pos]!='9') ++pos;
  swap(s[pos], s[3]);

  s=s.substr(4);
  int modS=mod(s);
  int startT=1;
  for(auto& i:s)
    startT = (startT*10) % 7;
  vector<int> t{1,6,8,9};

  do{

    if((mod(t,startT)+modS)%7==0){
      for(int i:t)
	cout << i;      
      cout << s;
      cout << '\n';
      return 0;
    }
  }while(next_permutation(begin(t), end(t)));

  cout << "0\n";
}
