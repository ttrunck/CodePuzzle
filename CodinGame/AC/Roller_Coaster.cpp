#include<iostream>
#include<vector>

using namespace std;

typedef pair<int,long long> pi;

const int NBTOUR = 32;

int main(){
  int L,C,N;
  cin >> L >> C >> N;
  vector<int> P(N);
  for(int i=0;i<N;++i)
    cin >> P[i];

  vector<vector<pi> > t(NBTOUR, vector<pi>(N));

  int nbpeople=0;
  int curr=0;
  for(int i=0;i<N;++i){
    while(nbpeople+P[curr]<=L){
      nbpeople+=P[curr];
      curr=(curr+1)%N;
      if(curr==i)
	break;
    }
    t[0][i]=pi(curr,nbpeople);
    nbpeople-=P[i];
  }

  for(int i=1;i<NBTOUR;++i)
    for(int j=0;j<N;++j)
      t[i][j]=pi(t[i-1][t[i-1][j].first].first,t[i-1][j].second+t[i-1][t[i-1][j].first].second);

  
  int pos=0;
  long long res=0;
  int bit=0;
  while(C!=0){
    if(C%2==1){
      res+=t[bit][pos].second;
      pos=t[bit][pos].first;
    }
    bit++;
    C/=2;
  }

  cout << res << '\n';
}
