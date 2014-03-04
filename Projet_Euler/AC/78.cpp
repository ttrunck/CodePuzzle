#include<iostream>
#include<vector>

using namespace std;

typedef long long ent;

int const N=60000;
int res[N];
int M=1000000;

int main(){
  for(int i=0;i<N;++i)
    res[i]=0;

  for(int i=1;i<N;++i){
    res[i]=(res[i]+1)%M;
    if(res[i]==0){
      cout << i << '\n';
      return 0;
    }
    for(int j=i;j<N;++j)
      res[j]=(res[j]+res[j-i])%M;
  }
}
