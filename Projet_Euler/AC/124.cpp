#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int const n=100000;

vector<int> rad;
vector<int> t;

bool f(int a, int b){
  return (rad[a]<rad[b] || (rad[a]==rad[b] && a<b));
}

int frad(int n){
  int res=1;
  for(int i=2;n!=1;++i)
    if(n%i==0){
      res*=i;
      while(n%i==0) n/=i;
    }
  return res;
}

int main(){
  rad.push_back(-1);
  for(int i=1;i<=n;++i){
    t.push_back(i);
    rad.push_back(frad(i));
  }
  sort(t.begin(),t.end(),f);
  cout << t[10000-1] << '\n';
}
