#include<iostream>

using namespace std;

const int N=300009;
int c[5]={1,5,10,25,50};
long long t[N][5];

long long aux(const int n, const int m){
  
  if(n<0) return 0;
  if(m<0) return 0;
  if(m==0) return 1;

  if(t[n][m]!=-1) return t[n][m];
  long long res=aux(n, m-1);

  int nn=n;
  while(nn-c[m]>=0){
    res+=aux(nn-c[m],m-1);
    nn-=c[m];
  }

  t[n][m]=res;
  return res;
}


int main(){
  for(int i=0;i<N;++i)
    for(int j=0;j<5;++j)
      t[i][j]=-1;
  int n;
  while(cin >> n){
    if(aux(n,4)==1)
      cout << "There is only 1 way to produce "<< n <<" cents change." << endl; 
    else
      cout << "There are " << aux(n,4) << " ways to produce "<< n <<" cents change." << endl;
  }
}
