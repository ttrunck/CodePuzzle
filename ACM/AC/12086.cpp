#include<iostream>
#include<vector>
#include<string>

using namespace std;

int sum(int x, int y, const vector<int> & t){
  if(x==0){
    int res=0;
    while(y>=0){
      res+=t[y];
      y=(y&(y+1))-1;
    }
    return res;
  }
  else
    return sum(0,y,t)-sum(0,x-1,t);
}

void mod(int y, int val, vector<int> &t, vector<int> & m) {
  int inc=val-m[y];
  m[y]=val;
  while(y<int(t.size())){
    t[y]+=inc;
    y=y|(y+1);
  }
}

/*
void mod(int x, int val, vector<int> & t, vector<int> & m){
  t[x]=val;
}

int sum(int x, int y, const vector<int> & t){
  int res=0;
  for(int i=x;i<=y;++i)
    res+=t[i];
  return res;
}
*/
int main(){
  int icase=1;
  bool first=true;
  int n;
  ios::sync_with_stdio(false);
  while(cin >> n && n){
    if(!first)
      cout << '\n';
    first=false;
    cout << "Case " << icase++ << ":\n";
    vector<int> t(n,0);
    vector<int> m(n,0);
    for(int i=0;i<n;++i){
      int tmp;
      cin >> tmp;
      mod(i,tmp,t,m);
    }

    /*
    for(int i=0;i<int(t.size());++i)
      cerr << t[i] << ' ';
    cerr << endl;
    */
    string action;
    while(cin >> action && action!="END"){
      int x,y;
      cin >> x >> y;
      if(action=="S")
	mod(x-1,y, t,m);
      else
	cout << sum(x-1,y-1, t) << '\n';
    }
  }
}
