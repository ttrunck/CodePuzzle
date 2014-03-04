#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int const N=100009;
int t[N];
int n;
int mema[N];

long long merge(int a, int b){
  // cout << a << ' ' << b<< endl;
  if(a+1>=b) return 0;
  long long res=0;
  const int m=a+(b-a)/2;
  res+=merge(a,m);
  res+=merge(m,b);
    
  int ca=a;
  int cb=m;
  for(int i=a;i<b;++i)
    if((t[ca]<t[cb] && ca<m) || (cb>=b))
      mema[i]=t[ca++];
    else{
      res+=m-ca;
      mema[i]=t[cb++];
    }
  for(int i=a;i<b;++i)
    t[i]=mema[i];
  return res;
}

int main(){
 scanf("%d", &n);
 while(n!=0){
   for(int i=0;i<n;++i)
     scanf("%d", &t[i]);
   long long res=merge(0,n);
   if(res%2!=0)
      cout << "Marcelo" << endl;
    else
      cout << "Carlos" << endl;
 scanf("%d", &n);
  }
}
