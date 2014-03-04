#include<iostream>
#include<vector>
using namespace std;

int const N=1000000;
bool prime[N];
vector<int> p;
int const D=4;

bool prop(int n){
  int nb_div=0;
  int nn=n;
  int curr=0;
  while(nn!=1){
    if(nn%p[curr]==0){
      nb_div++;
      while(nn%p[curr]==0)
	nn/=p[curr];
    }
    if(nb_div>D) return false;
    curr++;
  }
  return nb_div==D;
}

int main(){
  for(int i=0;i<N;++i)
    prime[i]=(i%2==1);
  prime[1]=false;
  prime[2]=true;
  for(int i=3;i<N;++i)
    for(int j=i+i;j<N;j+=i)
      prime[j]=false;

  for(int i=0;i<N;++i)
    if(prime[i]) p.push_back(i);

  int i=1;
  while(!(prop(i)&&prop(i+1)&&prop(i+2)&&prop(i+3))) i++;
  cout << i << '\n';
}
