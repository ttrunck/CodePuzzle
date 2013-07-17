#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<stack>

using namespace std;

int aux(int x, int y, const vector<string> & t){
  vector<vector<bool> > vu(t.size(),vector<bool>(t[0].size(),false));
  int res=1;
  vu[x][y]=true;
  stack<pair<int, int> > s;
  s.push(make_pair(x,y));
  while(!s.empty()){
    int x=s.top().first, y=s.top().second;
    s.pop();
    for(int i=-1;i<=1;++i)
      for(int j=-1;j<=1;++j)
	if(x+i>=0 && y+j>=0 && x+i<int(t.size()) && y+j<int(t[0].size()) && t[x+i][y+j]=='W' && !vu[x+i][y+j]){
	  res++;
	  vu[x+i][y+j]=true;
	  s.push(make_pair(x+i,y+j));
	}
  }
  return res;
}

int main(){
  int cas;
  bool first=true;
  cin >> cas;
  cin.ignore();
  cin.ignore();
  while(cas--){
    if(first)
      first=false;
    else
      cout << '\n';
    vector<string> t;
    string s;
    while(getline(cin, s) && (s[0]=='L' || s[0]=='W'))
      t.push_back(s);

    //   for(int i=0;i<t.size();++i)
    //  cerr << t[i] << endl;

    do{
      int x,y;
      istringstream(s)>> x >> y;
      cout << aux(x-1,y-1,t) << '\n';
    }while(getline(cin,s) && !s.empty());
  }
}
