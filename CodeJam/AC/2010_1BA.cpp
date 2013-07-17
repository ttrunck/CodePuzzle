#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<sstream>

using namespace std;

int main(){
  int nbcase;
  cin >> nbcase;
  for(int icase=1;icase<=nbcase;++icase){
    cout << "Case #" << icase << ": ";
    int N, M;
    cin >> N >> M;
    set<string> dir;

    for(int i=0;i<N;++i){
      string s;
      cin >> s;
      for(int j=1;j<int(s.size());++j)
	if(s[j]=='/')
	  dir.insert(s.substr(0, j));
      dir.insert(s);
    }

    int pred=dir.size();
    for(int i=0;i<M;++i){
      string s;
      cin >> s;
      for(int j=1;j<int(s.size());++j)
	if(s[j]=='/')
	  dir.insert(s.substr(0, j));
      dir.insert(s);
    }
    /*
    for(auto it=begin(dir);it!=end(dir);++it)
      cerr << *it << ' ';
    cerr << endl;
    */
    cout << dir.size()-pred << '\n';
  }
}
