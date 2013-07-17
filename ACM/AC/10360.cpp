#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int const N=1025;
int t[N][N];
int s[N+1][N+1];
int d;

int aux(int x, int y){
  return s[min(x+d+1,N-1)][min(y+d+1,N-1)]
    -s[min(x+d+1,N-1)][max(y-d,0)]
    -s[max(x-d,0)][min(y+d+1,N-1)]
    +s[max(x-d,0)][max(y-d,0)];
}

int main(){
  int cas;
  cin >> cas;
  while(cas--){
    for(int i=0;i<N;++i)
      for(int j=0;j<N;++j){
	t[i][j]=0;
	s[i][j]=0;
      }
    int n;
    cin >> d >> n;
    for(int i=0;i<n;++i){
      int x,y,p;
      cin >> x >> y >> p;
      t[x][y]=p;
    }
    for(int i=1;i<=N;++i)
      for(int j=1;j<=N;++j)
	s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+t[i-1][j-1];
    
    int kill=-1;
    int x,y;
    for(int i=0;i<N;++i)
      for(int j=0;j<N;++j){
	int tmp=aux(i,j);
	if(kill<tmp){
	  kill=tmp;
	  x=i;
	  y=j;
	}
      }
    cout << x << ' ' << y << ' ' << kill << endl;
  }
}
