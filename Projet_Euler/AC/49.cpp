#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

int const N=10000;

bool prime[N];

bool prop(int a, int b){
  ostringstream ta, tb;
  ta << a;
  tb << b;
  string sa=ta.str();
  string sb=tb.str();
  
  sort(sa.begin(),sa.end());
  sort(sb.begin(),sb.end());

  return sa==sb;
}

int main(){
  for(int i=0;i<N;++i)
    prime[i]=(i%2==1);
  prime[1]=false;
  prime[2]=true;
  for(int i=3;i<N;++i)
    for(int j=i+i;j<N;j+=i)
      prime[j]=false;

  for(int i=1000;i<N;++i)
    for(int j=1;i+j+j<N;++j){
      if(prime[i] && prime[i+j] && prime[i+j+j] && prop(i,i+j) && prop(i,i+j+j))
	cout << i << i+j << i+j+j << '\n';
    }
}
