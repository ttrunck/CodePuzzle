#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int t[40];

int play(int n){
  n= (n+(rand()%4+1)+(rand()%4+1))%40;
  if(n==30) return 10;
  if(n==2||n==17||n==33){
    int tmp=rand()%16;
    if(tmp==0) return 0;
    if(tmp==1) return 10;
  }
  if(n==7||n==22||n==36){
    int tmp=rand()%16;
    if(tmp==0) return 0;
    if(tmp==1) return 10;
    if(tmp==2) return 11;
    if(tmp==3) return 24;
    if(tmp==4) return 39;
    if(tmp==5) return 5;
    if(tmp==6 || tmp==7){
      if(n==7) return 15;
      if(n==22) return 25;
      if(n==36) return 5;
    }
    if(tmp==8){
      if(n==7) return 12;
      if(n==22) return 28;
      if(n==36) return 12;
    }
    if(tmp==9) return (n-3+40)%40;
  }
  return n;
}

int main(){
  for(int i=0;i<40;++i)
    t[i]=0;
  srand(time(NULL));
  
  int pos=0;
  for(int i=0;i<10000000;++i){
    pos=play(pos);
    t[pos]++;
  }

  for(int i=0;i<3;++i){
    int maxi=0;
    int res=-1;
    for(int j=0;j<40;++j)
      if(t[j]>maxi){
	maxi=t[j];
	res=j;
      }
    t[res]=-1;
    cout << res;
  }
  cout << '\n';
}
