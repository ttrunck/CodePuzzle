#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

ll good(int n, int k, int l, int m, vector<vector<vector<vector<ll> > > >& mem){
  if(n==0) return 1;

  if(mem[n][k][l][m]!=-1) return mem[n][k][l][m];

  ll res=0;

  if(m>0)
    res+=good(n-1,l,0,m,mem);

  for(int i=1;i+k+l<=9;++i)
    res+=good(n-1,l,i,1,mem);

  return mem[n][k][l][m]=res;
}

int main(){

  vector<vector<vector<vector<ll> > > > mem(21, vector<vector<vector<ll> > >(10, vector<vector<ll> >(10,vector<ll>(2,-1))));
  cout << good(20,0,0,0,mem) << endl;
}
