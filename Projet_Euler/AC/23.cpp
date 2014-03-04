#include <iostream>
#include <cmath>

using namespace std;

int const N=30000;
bool abundant[N];
bool be_written[N];

int proper_div(int n){
  int res=0;
  for(int i=1;i<n;++i)
    if(n%i==0)res+=i;
  return res;
}

int main(){
  for(int i=0;i<N;++i)
    abundant[i]=(proper_div(i)>i);

  for(int i=0;i<N;++i)
    be_written[i]=false;

  for(int i=0;i<N;++i)
    if(abundant[i])
      for(int j=0;j+i<N;++j)
	be_written[i+j]= be_written[i+j] || abundant[j];
      
  int res=0;
  for(int i=0;i<N;++i)
    if(!be_written[i]){
      cout << i << '\n';
      res+=i;
    }

  cout << '\n' << res << '\n';
}
