#include<iostream>

using namespace std;

int const N=12;
int t[N];

bool pluzun(){
  t[0]++;
  for(int i=0;i<N-1;++i)
    if(t[i]>2){
      t[i]=0;
      t[i+1]++;
    }
  return (t[N-1]<=2);
}

bool check(){
  int vu1=0;
  int vu2=0;
  bool vu12=false;
  for(int i=0;i<N;++i){
    if(t[i]==1){
      vu1++;
      if(!vu2)
	vu12=true;
    }
    if(t[i]==2)
      vu2++;
  }
  if(vu1==0 || vu2==0 || !vu12) return false;
  if(vu1!=vu2) return false;
  int tmp=0;
  for(int i=0;i<N;++i){
    if(t[i]==1) tmp++;
    if(t[i]==2) tmp--;
    if(tmp<0) return true;
  }
return false;
}

void print(){
  for(int i=0;i<N;++i)
    cout << t[i];
  cout << endl;
}

int main(){
  int res=0;
  while(pluzun())
    if(check()){
      res++;
      //  print();
    }
  cout << res << endl;
}
