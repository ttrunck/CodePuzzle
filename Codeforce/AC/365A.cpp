#include<iostream>
#include<set>

using namespace std;

bool good(int k, int n){
  set<int> s;
  while(n!=0){
    s.insert(n%10);
    n/=10;
  }

  for(int i=0;i<=k;++i)
    if(s.find(i)==end(s))
      return false;

  return true;
}

int main(){
  int n, k;
  cin >> n >> k;
  int res=0;
  for(int i=0;i<n;++i){
    int t;
    cin >> t;
    if(good(k,t))
      ++res;
  }

  cout << res << '\n';
}
