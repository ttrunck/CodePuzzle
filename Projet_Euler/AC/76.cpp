#include<iostream>

using namespace std;

int const N=100;

int count[N+1][N+1];

int count_fun(int n, int p){
  if(count[n][p]!=-1) return count[n][p];
  if(p==1) return 1;
  int res=0;
  for(int k=0;n-p*k>=0;++k)
    res+=count_fun(n-p*k,p-1);
  count[n][p]=res;
  return res;
}

int main(){
  for(int i=0;i<N+1;++i)
    for(int j=0;j<N+1;++j)
      count[i][j]=-1;

  cout << count_fun(N,N-1) << '\n';

}
