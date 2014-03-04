#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;

int const N=5000;

bool prime[N];
vector<int> p;

bool permut(int a, int b){
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
  for(int i=0;i<N;++i){
    prime[i]=(i%2==1);
  }
  prime[1]=false;
  prime[2]=true;
  for(int i=3;i<N;++i)
    if(prime[i])
      for(int j=i+i;j<N;j+=i)
	prime[j]=false;
  
  for(int i=2;i<N;++i)
    if(prime[i]) p.push_back(i);
  
  double mini=100;
  int res=-2,phires=1;

  for(int i=0;i<p.size();++i)
    for(int j=i+1;j<p.size();++j){
      int n=p[i]*p[j];
      int phi=(p[i]-1)*(p[j]-1);
      if(n<10000000 && permut(n,phi) && (double)n/(double)phi<mini){
      res=n;
      phires=phi;
      mini=(double)n/(double)phi;
      }
    }
  
  cout << res << ' ' << phires << '\n';
}
