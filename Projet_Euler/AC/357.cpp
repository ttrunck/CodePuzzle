#include<iostream>

typedef long long ent;

using namespace std;

int const N=100000000;
bool prime[N];

bool ok(int n){
  for(int i=1;i*i<=n;++i)
    if(n%i==0 && !prime[i+n/i]) return false;
  return true;
}

int main(){
  for(int i=0;i<N;++i)
    prime[i]=(i%2==1);
  prime[1]=false;
  prime[2]=true;
  for(int i=3;i*i<N;++i)
    if(prime[i])
      for(int j=i+i;j<N;j+=i)
	prime[j]=false;
  
  cout << "Initialisation done\n";

  ent res=1;
  for(int i=0;i<=N;i+=2)
    if(ok(i)){
      res+=i;
    }
  cout << res << '\n';

}
