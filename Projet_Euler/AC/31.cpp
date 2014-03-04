#include<iostream>

using namespace std;

int count_tab[201][8];
int val[8]={1,2,5,10,20,50,100,200};

int count(int v, int p){
  int vv=v;
  if(count_tab[v][p]!=-1) return count_tab[v][p];
  if(p==0) return 1;
  if(v==0) return 1;
  int res=0;
  while(vv>=0){
    res+=count(vv,p-1);
    vv-=val[p];
  }
  count_tab[v][p]=res;
  return res;
}

int main(){
  for(int i=0;i<201;i++)
    for(int j=0;j<8;++j)
      count_tab[i][j]=-1;
  
  cout << count(200,7) << '\n'; 
}
