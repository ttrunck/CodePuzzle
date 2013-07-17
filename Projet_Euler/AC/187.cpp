#include<iostream>
#include<vector>

using namespace std;

const int N=100000000;

int nb(int j, int i){
  int res=0;
  while(j%i==0){
    j/=i;
    res++;
  }
  return res;
}

int main(){

  vector<int> p(N, 0);
  p[0]=0;p[1]=0;
  for(int i=2;i<N;++i)
    if(p[i]==0)
      for(int j=i;j<N;j+=i)
	p[j]+=nb(j,i);

  /* 
 for(int i=2;i<N;++i)
    if(p[i]==2)
      cerr << i << ' ';
  */

  int res=0;
  for(int i=2;i<N;++i)
    if(p[i]==2)
      res++;
  
  cout << res << endl;
}
