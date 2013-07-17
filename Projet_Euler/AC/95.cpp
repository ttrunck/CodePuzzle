#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int const L=1000000;
int mem[L];

int next(int n){
  if(mem[n]!=-1) return mem[n];
  int res=1;
  for(int i=2;i*i<n;++i)
    if(n%i==0) res+=i+n/i;
  mem[n]=res;
  return res;
}

int taille(int n){
  vector<int> t;
  int res=0;
  int nn=n;
  while(count(t.begin(),t.end(),nn)==0){
    t.push_back(nn);
    nn=next(nn);
    if(nn<n) return 0;
    if(nn>L) return 0;
    res++;
  }
  if(n==nn) return res;
  return 0;
}

int main(){
  for(int i=0;i<L;++i)
    mem[i]=-1;
  int maxi=0, res=0;
  for(int i=1;i<L;++i)
      if(taille(i)>maxi){
	maxi= taille(i);
	res=i;
      }
  cout << res << '\n';
}
