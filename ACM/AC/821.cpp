#include<iostream>
#include<iomanip>

using namespace std;

const int N=109;

int t[N][N];

void floyd(){
 for(int k=0;k<N;++k){
   for(int i=0;i<N;++i)
     for(int j=0;j<N;++j)
	t[i][j]=min(t[i][j], t[i][k]+t[k][j]);
      }
}

int main(){
  int cas=1;
  int a,b;
  cin >> a >> b;
  while(a!=0 || b!=0){
    for(int i=0;i<N;++i)
      for(int j=0;j<N;++j)
	t[i][j]=N*N;

    t[a][b]=1;
    cin >> a >> b;
    while(a!=0 || b!=0){
      t[a][b]=1;
      cin >> a >> b;
    }

    floyd();

  double val=0, nb=0;
  for(int i=0;i<N;++i)
    for(int j=0;j<N;++j){
      if(i==j) continue;
      if(t[i][j]<N*N){
	val+=t[i][j];
	nb++;
      }
    }
  cout << "Case " << cas++ << ": average length between pages = " << setprecision(3) << fixed << val/nb << " clicks" << endl;
  
  cin >> a >> b;
  }
}
