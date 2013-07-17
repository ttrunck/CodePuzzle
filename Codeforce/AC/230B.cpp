#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

typedef long long ent;
const int N=2000009;
vector<bool> prime(N,true);

bool aux(ent n){
  ent k=sqrt(n);
  for(ent i=max(ent(0),k-2);i<k+3;++i)
    if(i*i==n && prime[i]) return true;

  return false;
}

int main(){
 
  prime[0]=false;
  prime[1]=false;
  for(int i=0;i<N;++i)
    if(prime[i])
      for(int j=i+i;j<N;j+=i)
	prime[j]=false;

  int n;
  cin >> n;
  for(int i=0;i<n;++i){
    ent tmp;
    cin >> tmp;
    if(aux(tmp))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
