#include<iostream>
#include<string>

using namespace std;

string convert(int c){
  string res="";
  for(int tmp=0;tmp<7;++tmp){
    res=(c%2?"1":"0")+res;
    c/=2;
  }
  return res;
}

int main(){
  string s;
  getline(cin, s);
 
  string res="";
  for(int c:s)
    res=res+convert(c);

  cerr << res << endl;

  int i=0;
  bool first=true;
  while(i<int(res.size())){
    if(!first)
      cout << ' ';
    first=false;
    if(res[i]=='0')
      cout << "00 0";
    else
      cout << "0 0";
    ++i;
    while(i<int(res.size()) && res[i]==res[i-1]){
      cout << '0';
      i++;
    }
  }
}
