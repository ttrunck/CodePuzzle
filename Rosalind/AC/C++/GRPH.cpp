#include<iostream>
#include<string>
#include<map>

using namespace std;

void get_fasta(map<string, string> & m){
  string lab, s, tmp;
  bool first=true;
  while(cin >> tmp){
    if(tmp[0]=='>'){
      if(!first)
	m[lab]=s;
      first=false;
      lab.clear();
      s.clear();
      lab=tmp.substr(1);
    }
    else
      s+=tmp;
  }
  m[lab]=s;
}

bool match(string & s, string & t){
  // cerr << s << ' ' << t << endl;
  // cerr << s.substr(0,3) << ' ' << t.substr(t.size()-4,3) << endl;
  return s.substr(s.size()-3,3)==t.substr(0,3);
}

int main(){
  map<string, string> m;
  get_fasta(m);
  /* 
 for(auto it=m.begin();it!=m.end();++it)
    cerr << it->first << '\n' << it->second << endl;
  */
  for(auto it=m.begin();it!=m.end();++it)
    for(auto it2=m.begin();it2!=m.end();++it2){
      if(it==it2) continue;
      if(match(it->second, it2->second))
	cout << it-> first << ' ' << it2->first << '\n';
    }
}
