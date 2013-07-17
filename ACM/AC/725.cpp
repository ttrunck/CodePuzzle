#include<iostream>
#include<algorithm>

using namespace std;

int N;
int t[10];

int ok(int a, int b){
  int tab[10];
  for(int i=0;i<10;++i)
    tab[i]=0;
  for(int i=0;i<5;++i){
    tab[a%10]++;
    tab[b%10]++;
    a/=10;
    b/=10;
  }
  for(int i=0;i<10;++i)
    if(tab[i]!=1) return false;
  return true;
}

int main(){
  cin >> N;
  while(N!=0){
    int res=0;
      for(int num=1;num<100000;++num){
	int dem=num/N;
	if(dem*N==num && ok(num, dem)){
	  cout << num << " / " ;
	  if(dem/10000==0) cout << '0';
	  cout << dem;
	  cout << " = " << N << endl; 
	  res++;
	}
      }
    if(res==0)
      cout << "There are no solutions for " << N << '.' << endl;
    
    cin >> N;
    if(N!=0)
      cout << endl;
  }
}
