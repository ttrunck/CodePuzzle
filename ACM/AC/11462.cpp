#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

int const N=109;
int t[N];

int main(){
  int n;
  scanf("%d",&n);
  while(n!=0){
    bool p=true;
    for(int i=0;i<N;++i)
      t[i]=0;

    for(int i=0;i<n;++i){
      int tmp;
      scanf("%d",&tmp);
      t[tmp]++;
    }
    
    for(int i=0;i<N;++i)
      if(t[i]!=0){
	for(int j=0;j<t[i];++j){
	  if(!p)
	    printf(" ");
	  printf("%d", i);
	  p=false;
	}
      }
    printf("\n");

    scanf("%d",&n);
  }
}
