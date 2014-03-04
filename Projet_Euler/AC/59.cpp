#include<iostream>
#include<vector>
using namespace std;

vector<int> t;

bool check(){
  for(int i=0;i<t.size();++i)
    if(!isprint((char)t[i])) return false;
  return true;
}

int main(){
  int tmp;
  while(cin >> tmp){
    t.push_back(tmp);
  }
  int res=0;
  /*
  for(int a=0;a<26;++a)
    for(int b=0;b<26;++b)
      for(int c=0;c<26;++c){
  */
  int a=6,b=14,c=3;
	for(int i=0;i<t.size();++i){
	  if(i%3==0) t[i]^=a+'a';
	  if(i%3==1) t[i]^=b+'a';
	  if(i%3==2) t[i]^=c+'a';
	}
	
	if(check()){
	  cout << a << ' ' << b << ' ' << c << '\n';
	  for(int i=0;i<t.size();++i){
	    res+=t[i];
	  }
	  
	  cout << '\n' << '\n';
	}
	for(int i=0;i<t.size();++i){
	  if(i%3==0) t[i]^=a+'a';
	  if(i%3==1) t[i]^=b+'a';
	  if(i%3==2) t[i]^=c+'a';
	}

	cout << res << '\n';
      
}
