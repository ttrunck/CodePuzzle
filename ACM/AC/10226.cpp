#include<iostream>
#include<map>
#include<string>
#include<cstdio>
#include<iomanip>

using namespace std;

map<string, int> m;
int tot;

int main(){
  int cas;
  cin >> cas;
  string line;
    getline(cin, line);
    getline(cin, line);
  while(cas--){
    m.clear();
    tot=0;
    while(getline(cin, line) && !line.empty()){
      tot++;
      m[line]++;
    }
    map<string,int>::iterator it=m.begin();
    for(;it!=m.end();++it)
      cout << it->first << ' ' << fixed << setprecision (4) << (double)it->second/(double)tot*100 << endl;
    if(cas!=0) cout << endl;
  }

}
