#include<iostream>
#include<cmath>

using namespace std;

int t[109][25009];
int c[109];

int aux(int m, int cible){
  if(m<0) return 0;
  if(cible<=0) return 0;

  if(t[m][cible]!=-1) return t[m][cible]; 

  int res=aux(m-1,cible);
  if(c[m]<=cible)
    res=max(res,c[m]+aux(m-1, cible-c[m]));
  
  t[m][cible]=res;
  return res;
}

int main(){
  int cas;
  cin >> cas;
  while(cas--){


    int m;
    cin >> m;
    int sum=0;
    for(int i=0;i<m;++i){
      cin >> c[i];
      sum+=c[i];
    }
    
    for(int i=0;i<m;++i)
      for(int j=0;j<=(sum+1)/2;++j)
	t[i][j]=-1;

    int res=aux(m-1,(sum+1)/2);
    cout << abs(sum-res-res) << endl;

  }
}
