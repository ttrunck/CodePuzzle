#include<iostream>

using namespace std;

typedef long long ent;

ent aux(ent n, ent k, ent b){
  if(n==0 && b<k) return 0;
  return n+aux((b+n)/k,k,(b+n)%k);
}

int main(){
  ent n, k;
  while(cin >> n >> k){
    cout << aux(n,k,0) << endl;
  }
}
