#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<map>

using namespace std;

string line;
vector<int> t;
vector<string> f;
map<int, string> m;

int main(){
  int n;
  cin >> n;
  cin.ignore();
  while(n--){
    t.clear(); 
    f.clear();
    m.clear();
    cin.ignore();
    getline(cin, line);
    istringstream iss;
    iss.str(line);
    int tmp;
    while(iss >> tmp)
      t.push_back(tmp-1);

    getline(cin, line);
    istringstream jss;
    jss.str(line);
    string fmp;
    while(jss >> fmp)
      f.push_back(fmp);
    

    for(int i=0;i<t.size();++i)
      m[t[i]]=f[i];
      
    map<int, string>::iterator it=m.begin();
    for(;it!=m.end();++it)
      cout << it->second << endl;
    if(n!=0)
      cout << endl;
  }
}
