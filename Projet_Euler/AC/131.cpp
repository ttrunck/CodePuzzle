#include<iostream>

using namespace std;

int const P=1000000;
int p[P];

int main(){
  for(int i=0;i<P;++i)
    p[i]=(i%2==1);
  p[1]=false;
  p[2]=true;
  for(int i=3;i<P;++i)
    if(p[i])
      for(int j=i+i;j<P;j+=i)
	p[j]=false;

  int res=0;
  
  for(int i=1;3*i*i-3*i+1<P;++i){
      int tmp=3*i*i-3*i+1;
      if(p[tmp]){
	//	cout << tmp <<  endl;
	res++;
      }
    }
  cout << res << '\n';
}

