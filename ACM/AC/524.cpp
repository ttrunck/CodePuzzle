#include<iostream>
#include<vector>

using namespace std;

bool isPrime(int n){
  for(int i=2;i*i<=n;++i)
    if(n%i==0)
      return false;
  return true;
}

bool ok(int n, int s, const vector<int>&t){
  for(int i=0;i<s;++i)
    if(t[i]==n) return false;
  return true;
}

void backtrack(int s, int n, vector<int>&t){
  if(s==n){
    if(isPrime(t.back()+1)){
    cout << 1;
    for(int i=1;i<n;++i)
      cout << ' ' << t[i];
    cout << '\n';
    }
    return;
  }

  for(int i=2;i<=n;++i){
    if(isPrime(i+t[s-1]) && ok(i,s,t)){
      t[s]=i;
      backtrack(s+1,n,t);
    }
  }

}

int main(){
 int icase=1;
  int n;
  while(cin >> n && n){
    if(icase>1)
      cout << '\n';
    cout << "Case " << icase++ << ":\n";
    vector<int> t(n);
    t[0]=1;
    backtrack(1,n,t);
  }
}
