#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int node=2;
const int N=10000;
vector<vector<bool> > g(N, vector<bool>(N, false));

void ae(int a, int b){
  g[a][b]=true;
  g[b][a]=true;
}

void add(int nb, int l){
  vector<int> n1(nb);
  for(int i=0;i<nb;++i){
    n1[i]=node;
    ++node;
  }
  vector<int> n2(nb);
  for(int i=0;i<nb;++i){
    n2[i]=node;
    ++node;
  }

  if(nb==l){
    ae(n1.back(), 1);
    ae(n2.back(), 1);
  }
  else{
    ae(n1.back(), 2+nb);
    ae(n2.back(), 2+nb);
  }

  ae(0,n1[0]);

  for(int i=1;i<int(n1.size());++i)
    ae(n1[i-1], n1[i]);

  if(n2.size()>0){
    ae(0, n2[0]);

    for(int i=1;i<int(n2.size());++i){
      ae(n2[i-1], n2[i]);
      ae(n2[i-1], n1[i]);
      ae(n1[i-1], n2[i]);
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  int k;
  cin >> k;

  vector<int> bin;
  while(k){
    bin.push_back(k%2?1:0);
    k/=2;
  }

  //for(int x:bin)
  //  cerr << x;
  //cerr << '\n';

  for(int i=0;i<int(bin.size())-2;++i){
    ae(node, node+1);
    ++node;
  }
  ae(node, 1);
  ++node;

  if(bin[0]==1)
    ae(0, 2);

  for(int i=1;i<int(bin.size());++i)
    if(bin[i]==1)
      add(i, int(bin.size())-1);

  cout << node << '\n';
  for(int i=0;i<node;++i){
    for(int j=0;j<node;++j)
      cout << (g[i][j]?'Y':'N');
    cout << '\n';
  }
}
