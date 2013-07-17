#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<utility>

using namespace std;

inline bool align(const pair<int, int> & a, const pair<int, int> & b, const pair<int, int> & c){
  return ((b.first-a.first)*(c.second-a.second)-(b.second-a.second)*(c.first-a.first))==0;
}

int main(){
  int nbcase;
  cin >> nbcase;
  cin.ignore();
  cin.ignore();
  bool first=true;
  
  while(nbcase--){
    if(!first) cout << '\n';
    first=false;

    string s;
    vector<pair<int, int> > t;
    while(getline(cin, s) && !s.empty()){
      stringstream ss(s);
      int a,b;
      ss >> a >> b;
      t.push_back(make_pair(a,b));
    }
    int res=1;
    for(int i=0;i<int(t.size());++i)
      for(int j=i+1;j<int(t.size());++j){
	int tmp=2;
	for(int k=j+1;k<int(t.size());++k)
	  if(align(t[i], t[j], t[k]))
	    tmp++;
	  res=max(res,tmp);
      }
	cout << res << '\n';
  }
}
