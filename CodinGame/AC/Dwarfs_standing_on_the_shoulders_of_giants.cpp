#include<iostream>
#include<vector>

using namespace std;

const int N=10009;

vector<vector<int> > t(N);
vector<int> mem(N,-1);

int longueur(int x){
  if(mem[x]!=-1) return mem[x];
  int res=1;
  for(int i : t[x])
    res = max(res, 1+longueur(i));
  return mem[x]=res;
}

int main(){
  int n;
  cin >> n;
  for(int i=0;i<n;++i){
    int a,b;
    cin >> a >> b;
    t[a].push_back(b);
  }

  int maxi=-1;
  for(int i=0;i<N;++i)
    maxi=max(maxi,longueur(i));

  cout << maxi << '\n';
}
