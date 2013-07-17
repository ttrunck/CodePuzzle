#include<iostream>
#include<string>
#include<map>

using namespace std;

string aux(int n, const string & s){
  map<string,int> m;
  for(int i=0;i<=int(s.size())-n;++i)
    m[s.substr(i,n)]++;

  string res;
  int maxi=0;
  for(map<string,int>::iterator it=m.begin();it!=m.end();++it){
    //cerr << it->first << ' ' << it->second << endl;
    if(it->second>maxi){
      maxi=it->second;
      res=it->first;
    }
  }

  return res;
}

int main(){
  int n;
  string s;
  while(cin >> n >> s)
    cout << aux(n,s) << '\n';
}
