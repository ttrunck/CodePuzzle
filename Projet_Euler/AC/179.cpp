#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>

using namespace std;

const int N=10000000;

int main(){
  vector<int> mem(N+1,0);
  
  for(int i=1;i<=N;++i)
    for(int j=i;j<=N;j+=i)
      mem[j]++;

  cout << "Done\n";

  int res=0;
  for(int i=1;i<N;++i)
    if(mem[i]==mem[i+1])
      res++;
  cout << res << endl;
}
