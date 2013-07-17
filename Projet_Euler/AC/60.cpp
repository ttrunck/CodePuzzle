#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int const N=100000000;
bool is_prime[N];
vector<int> prime;

int mini=10000000;
int const F=5;

int concat(int a, int b){
  int tmp=10;
  while(tmp<b) tmp*=10;
  return a*tmp+b;
}

bool compatible(vector<int> curr, int a){
  for(int i=0;i<curr.size();++i){
    if(!is_prime[concat(curr[i],a)]) return false;
    if(!is_prime[concat(a,curr[i])]) return false;
  }
  return true;
}

void aux(vector<int> curr, int t, int nb){
  int sum=0;
  for(int i=0;i<curr.size();++i)
    sum+=curr[i];
  if(sum>mini) return;
  if(nb==F){
    mini=sum;
    for(int i=0;i<curr.size();++i)
      cout << curr[i] << ' ';
    cout << '\n' << sum << '\n';
    return;
  }
  int tt=t;
  while(prime[tt]<10000 && !compatible(curr, prime[tt]))
    ++tt;
  if(prime[tt]>=10000) return;
  vector<int> curro;
  for(int i=0;i<curr.size();++i)
    curro.push_back(curr[i]);

  curr.push_back(prime[tt]);
  aux(curr,tt+1,nb+1);
  
  aux(curro,tt+1,nb);
}

int main(){
 for(int i=0;i<N;++i)
    is_prime[i]=(i%2==1);
  is_prime[1]=false;
  is_prime[2]=true;
  for(int i=3;i<N;++i)
    if(is_prime[i])
      for(int j=i+i;j<N;j+=i)
	is_prime[j]=false;

  for(int i=0;i<N;++i)
    if(is_prime[i]) prime.push_back(i);

  cout << "Initialisation terminée\n";

  vector<int> curr;
  aux(curr,0,0);

}
