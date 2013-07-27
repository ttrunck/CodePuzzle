#include<iostream>
#include<vector>

using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<bool> ho(n,true);
  vector<bool> ve(n,true);
  for(int i=0;i<m;++i){
    int x,y;
    cin >> x >> y;
    ho[x-1]=false;
    ve[y-1]=false;
  }

  int res=0;
  for(int i=1;i<n-1;++i){
    if(ho[i])
      res++;
    if(ve[i])
      res++;
  }

  if(n%2==1 && ho[n/2] && ve[n/2])
    res--;

  cout << res << endl;
}
