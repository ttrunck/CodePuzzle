#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N=1000001;
const long long MAX=1000000000001;

int main(){

  vector<bool> p(N,true);
  vector<long long> almost;
  p[1]=false;
  for(int i=2;i<N;++i)
    if(p[i]){
      long long tmp=(long long)(i)* (long long)(i);
      while(tmp<MAX){
	almost.push_back(tmp);
	tmp*=i;
      }
      for(int j=i+i;j<N;j+=i)
	p[j]=false;
    }
  sort(almost.begin(), almost.end());
  
  int cas;
  cin >> cas;
  while(cas--){
    long long lo, hi;
    cin >> lo >> hi;
    
    int res=0;
    for(int i=0;i<int(almost.size()) && almost[i]<=hi;++i)
      if(almost[i]>=lo && almost[i]<=hi) res++;

    cout << res << '\n';
  }
}
