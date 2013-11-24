#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>
using namespace std;

typedef pair<int, int> pi;

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  vector<int> b(n);

  for(int i=0;i<n;++i)
    cin >> a[i];
  for(int i=0;i<n;++i){
    cin >> b[i];
    b[i]=a[i]-k*b[i];
  }


  vector<vector<int> > mem(n+1, vector<int>(300000,-1));
    mem[0][150000]=0;
    for(int i=1;i<=n;++i)
      for(int j=50000;j<=250000;++j){
	mem[i][j]=mem[i-1][j];
	if(j-b[i-1]>=50000 && j-b[i-1]<=250000 && mem[i-1][j-b[i-1]]!=-1)
	  mem[i][j]=max(mem[i][j], mem[i-1][j-b[i-1]]+a[i-1]);
      }
  
  if(mem[n][150000]==0)
    cout << "-1\n";
  else
    cout << mem[n][150000] << '\n';
}
