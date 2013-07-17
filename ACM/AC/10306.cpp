#include<iostream>
#include<vector>
#include<utility>
#include<cmath>

using namespace std;

int S,m;
vector<pair<int,int> > t;
int const MAXI=100000000;

int mem[41][301][301];

int aux(int d, int co, int it){
  if(co*co+it*it==S*S) return 0;
  if(co*co+it*it>S*S) return MAXI;
  if(d>=m) return MAXI;
  if(mem[d][co][it]!=-1) return mem[d][co][it];
  int res=aux(d+1,co,it);
  int piece=0;
  while(co*co+it*it<S*S){
    co+=t[d].first;
    it+=t[d].second;
    piece++;
    res=min(res,aux(d+1,co,it)+piece);
  }
  mem[d][co][it]=res;
  return res;
}

void init(){
  for(int k=0;k<41;++k)
    for(int i=0;i<301;++i)
      for(int j=0;j<301;++j)
	mem[k][i][j]=-1;
}

int main(){
  int nb;
  cin >> nb;
  for(int cas=0;cas<nb;++cas){
    init();
    t.clear();
    cin >> m >> S;
    for(int i=0;i<m;++i){
      int co,it;
      cin >> co >> it;
      t.push_back(make_pair(co,it));
    }
    int tmp=aux(0,0,0);
    if(tmp!=MAXI)
      cout << tmp << endl;
    else
      cout << "not possible" << endl;
  }
}
