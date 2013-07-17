#include<iostream>
#include<vector>
#include<set>

using namespace std;

bool aseq(const vector<int> & t){
  set<int> s;
  s.insert(t[0]);
  for(int i=1;i<int(t.size());++i){
    // cerr << "S contain ";
    // for(set<int>::iterator it=s.begin();it!=s.end();++it)
    //   cerr << *it << ' ';
    // cerr << endl;
    if(t[i]<=t[i-1] || s.find(t[i])!=s.end())
      return false;
    set<int>::iterator it;
    set<int> sn=s;
    sn.insert(t[i]);
    for(it=s.begin();it!=s.end();++it)
      sn.insert((*it)+t[i]);
    s=sn;
  }
  return true;
}

int main(){
  int cas=1;
  int nb;
  while(cin >> nb){
    cout << "Case #" << cas++ << ':';
    vector<int> t(nb);
    for(int i=0;i<nb;++i)
      cin >> t[i];
    for(int i=0;i<nb;++i)
      cout << ' ' << t[i];

    if(aseq(t))
      cout << "\nThis is an A-sequence.\n";
    else
      cout << "\nThis is not an A-sequence.\n";

  }
}
