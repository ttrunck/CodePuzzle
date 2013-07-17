#include<iostream>
#include<utility>

using namespace std;

const int N=10009;

int m[109];
pair<int,int> t[109][N];

pair<int,int> aux(int p, int c){
  if(c<=0) return make_pair(0,0);
  if(p<0) return make_pair(0,0);
  
  if(t[p][c].first!=-1) return t[p][c];

  pair<int,int> res=aux(p-1, c);
  if(res.first<c) res=make_pair(N,N);
  pair<int,int> tmp= aux(p-1, c-m[p]);
  tmp.first+=m[p];
  tmp.second++;
  res=min(res,tmp);
  t[p][c]=res;
  return res;
}


int main(){
  int cas;
  cin >> cas;
  while(cas--){
    int cible, nb;
    cin >> cible >> nb;
    for(int i=0;i<nb;++i)
      cin >> m[i];
    
    for(int i=0;i<=nb;++i)
      for(int j=0;j<=cible;++j)
	t[i][j]=make_pair(-1,-1);

    pair<int,int> tmp=aux(nb-1,cible);
    cout << tmp.first << ' ' << tmp.second << endl;

  }
}
