#include<iostream>
#include<vector>

using namespace std;

const int N=209;
vector<int> t[N];
int c[N];

bool color(int n, int col){
  c[n]=col;
  bool res=true;
  
  for(int i=0;i<t[n].size();++i){
    if(c[t[n][i]]==-1)
      res=res && color(t[n][i], 1-col);
    else if(c[t[n][i]]!=1-col)
      return false;
  }
  
  return res;
  
}

int main(){
  int n, l;
  while(cin >> n >> l){
    for(int i=0;i<=n;++i){
      t[i].clear();
      c[i]=-1;
    }

    for(int i=0;i<l;++i){
      int a,b;
      cin >> a >> b;
      t[a].push_back(b);
      t[b].push_back(a);
    }

    if(color(1,0))
      cout << "BICOLORABLE." << endl;
    else
      cout << "NOT BICOLORABLE." << endl;
  }
}
