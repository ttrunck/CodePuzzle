#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int const N=12000;
int const M=15000;

bool ok[N+1];
vector<int> kk;

void val(int target, int acc, int nb, int n){
  for(int i=2;i<=sqrt(n);++i){
    if(n%i==0){
      int tmp= target-acc+nb-i-n/i+2;
      if(tmp<=N && !ok[tmp]){
	ok[tmp]=true;
	kk.push_back(target);
      }
      val(target, acc+i, nb+1, n/i);
    }
  }
}

int main(){
  for(int i=0;i<=N;++i)
    ok[i]=false;

  for(int i=0;i<M;++i)
    val(i, 0, 0, i);

  for(int i=2;i<=N;++i)
    if(!ok[i]){
      cout << "not ok " << i << '\n';
      return 0;
    }

  sort(kk.begin(),kk.end());
  kk.resize(unique(kk.begin(),kk.end())-kk.begin());
  int res=0;
  for(int i=0;i<kk.size();++i)
    res+=kk[i];
  cout << res << '\n';
}
