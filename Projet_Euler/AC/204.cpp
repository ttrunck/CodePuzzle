#include<iostream>
#include<vector>

using namespace std;

typedef long long ent;

const ent MAX=1000000000;

void aux(ent n, ent k, vector<ent> & t){
  while(n*k<=MAX){
    n*=k;
    t.push_back(n);
  }
}

bool prime(ent n){
  for(ent i=2;i*i<=n;++i)
    if(n%i==0) return false;
  return true;
}

int main(){

  vector<ent> p;
  for(int i=2;i<100;++i)
    if(prime(i))
      p.push_back(i);

  cerr << p.size() << endl;

  vector<ent> res;
  res.push_back(1);

  for(int i=0;i<int(p.size());++i){
    vector<ent> tmp;
    for(int j=0;j<int(res.size());++j){
      aux(res[j],p[i],tmp);
    }
    for(int j=0;j<int(tmp.size());++j)
      res.push_back(tmp[j]);
  }

  cout << res.size() << endl;
}
