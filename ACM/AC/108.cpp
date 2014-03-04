#include<iostream>

using namespace std;

int const N=101;
int n;
int t[N][N];
int s[N][N];

int ss(int a, int b, int c, int d){
  int res=s[c][d];
  if(a>0)
    res-=s[a-1][d];
  
  if(b>0)
    res-=s[c][b-1];
  if(a>0 && b>0)
    res+=s[a-1][b-1];
  return res;
}

int main(){
  cin >> n;
  for(int i=0;i<n;++i)
    for(int j=0;j<n;++j)
      cin >> t[i][j];

  s[0][0]=t[0][0];
  for(int i=1;i<n;++i){
    s[0][i]=t[0][i]+s[0][i-1];
    s[i][0]=t[i][0]+s[i-1][0];
  }

  for(int i=1;i<n;++i)
    for(int j=1;j<n;++j)
      s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+t[i][j];

  int res=-1000000;
  for(int a=0;a<n;++a)
  for(int b=0;b<n;++b)
  for(int c=a;c<n;++c)
  for(int d=b;d<n;++d)
    res=max(res,ss(a,b,c,d));

  cout << res << endl;
}
