#include <iostream>

using namespace std;

const int N=1000000007;

int m, n;
int tab[1<<10][11][102];

int solve(int last,int i,int state){
  if(tab[state][last][i]!=-1)
    return tab[state][last][i];
  int res = ((state==(1<<n)-1)&&i>=n);
  if(i<m){
      int a = last+1;
      int b = last-1;
      if(a<n)
	res = (res + (solve(a,i+1,state|(1<<a))%N))%N;
      if(b>=0)
	res = (res + (solve(b,i+1,state|(1<<b))%N))%N;
    }
  return tab[state][last][i]=res;
}
int main(){
  int t;
  cin >> t;
  while(t--)
    {
      cin >> n >> m;
      int l = 1<<n;
      for(int i=0;i<l;i++)
	for(int j=0;j<=n;j++)
	  for(int k=0;k<=m+1;k++)
	    tab[i][j][k]=-1;
      int res = 0;
      for(int i=1;i<n;i++)
	res = (res + ((solve(i,1,1<<i))%N))%N;
      cout << res << '\n';
    }
}

