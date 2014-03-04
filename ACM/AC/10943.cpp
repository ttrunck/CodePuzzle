#include<iostream>

using namespace std;

int const M=1000000;
int const N=101;

int t[N][N];

int aux(int n, int k){
  if(t[n][k]!=-1) return t[n][k];
  if(k==0) return (n==0)?1:0;
  int res=0;
  
  for(int i=0;i<=n;++i)
    res=(res+aux(n-i,k-1))%M;

  t[n][k]=res;
  return res;
}

int main(){
  for(int i=0;i<N;++i)
    for(int j=0;j<N;++j)
      t[i][j]=-1;

  int n,k;
  cin >> n >> k;
  while(n!=0 && k!=0){
    cout << aux(n,k) << endl;
    cin >> n >> k;
  }
}
