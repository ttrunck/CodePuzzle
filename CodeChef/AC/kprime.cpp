#include<iostream>
#include<vector>

using namespace std;

const int N=100009;

int main(){
  vector<int> prime(N);
  for(int i=2;i<N;++i)
    if(prime[i]==0)
      for(int j=i;j<N;j+=i)
	prime[j]++;


  int nb;
  cin >> nb;
  while(nb--){
    int a,b,k;
    cin >> a >> b >> k;
      int res=0;
    for(int i=a;i<=b;++i)
      if(prime[i]==k)
	++res;
    cout << res << '\n';
  }
}
