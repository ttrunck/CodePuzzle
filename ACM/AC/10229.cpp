#include<iostream>
#include<vector>
#include<cassert>

using namespace std;


typedef long long ll;
typedef vector<vector<ll>> matrix;

ll mod;

void mult(const matrix& a, const matrix& b, matrix& res){
  int n=a.size();
  vector<vector<ll>> tres(n, vector<ll>(n));

  for(int i=0;i<n;++i)
    for(int j=0;j<n;++j)
      for(int k=0;k<n;++k)
	tres[i][j] = (tres[i][j]+a[i][k]*b[k][j])%mod;


  res.clear();
  res.assign(n, vector<ll>(n, 0));
  for(int i=0;i<n;++i)
    for(int j=0;j<n;++j)
      res[i][j] = tres[i][j];
}

void exp(const matrix& a, int b, matrix& res){
  int n=a.size();
  res.clear();
  res.assign(n, vector<ll>(n, 0));
  for(int i=0;i<n;++i)
    res[i][i]=1;

  if(b==0) return;

  exp(a, b/2, res);
  mult(res, res, res);
  if(b%2==1)
    mult(a, res, res);
}


int main(){
  int n, m;
  while(cin >> n >> m){
    mod = 1<<m;

    vector<vector<ll>> a, res;
    a.push_back(vector<ll>{1,1});
    a.push_back(vector<ll>{1,0});
    exp(a, n, res);

    //cerr << res[0][0] << ' ' << res[0][1] << '\n';
    //cerr << res[1][0] << ' ' << res[1][1] << '\n';
    cout << res[1][0] << '\n';

  }
}
