#include<iostream>
#include<vector>

using namespace std;

int somme(int x, int y, const vector<int> & t){
  if(x==0){
    int res=0;
    while(y>=0){
      res+=t[y];
      y=(y&(y+1))-1;
    }
    return res;
  }
  else
    return somme(0,y,t)-somme(0,x-1,t);
}

void incremente(int x, int inc, vector<int> & t) {
  while(x<int(t.size())){
    t[x]+=inc;
    x=x|(x+1);
  }
}

int main(){
  ios::sync_with_stdio(false);
  int nbcase;
  cin >> nbcase;
  while(nbcase--){
    int n,m;
    cin >> n >> m;
    vector<int> t(n+m);
    vector<int> pos(n);
    for(int i=0;i<n;++i){
      pos[i]=m+i;
      incremente(pos[i],1,t);
    }
    for(int i=m-1;i>=0;--i){
      int film;
      cin >> film;
      cout << somme(0, pos[film-1]-1, t) << (i?' ':'\n');
      incremente(pos[film-1], -1, t);
      incremente(pos[film-1]=i, 1, t);
    }
  }
}
