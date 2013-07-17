#include<iostream>

using namespace std;

int const N=1000000;

bool is_ok[N];

bool check(int i, int j){
  int k=i*j;
  bool t[9];
  for(int l=0;l<9;++l)
    t[l]=false;
  while(i!=0){
    if(i%10==0) return false;
    if(t[i%10-1]) return false;
    t[i%10-1]=true;
    i/=10;
  }
  while(j!=0){
    if(j%10==0) return false;
    if(t[j%10-1]) return false;
    t[j%10-1]=true;
    j/=10;
  }
  while(k!=0){
    if(k%10==0) return false;
    if(t[k%10-1]) return false;
    t[k%10-1]=true;
    k/=10;
  }
  for(int l=0;l<9;++l)
    if(!t[l]) return false;
 return true;
}

int main(){
  for(int i=0;i<N;++i)
    is_ok[i]=false;
  
  for(int i=1;i<100;++i)
    for(int j=i;j<10000;++j)
	is_ok[i*j]=is_ok[i*j] || check(i,j);
  int res=0;
  for(int i=0;i<N;++i)
    if(is_ok[i])
      res+=i;
  cout << res << '\n';
}
