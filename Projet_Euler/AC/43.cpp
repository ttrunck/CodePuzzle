#include<iostream>
#include<algorithm>

using namespace std;

int t[]={0,1,2,3,4,5,6,7,8,9};

bool prop(){
  int tmp;
  int j=0;

  j++;
  tmp=0;
  for(int i=0;i<3;++i)
    tmp=tmp*10+t[i+j];
  if(tmp%2!=0) return false;
  
  j++;
  tmp=0;
  for(int i=0;i<3;++i)
    tmp=tmp*10+t[i+j];
  if(tmp%3!=0) return false;

  j++;
  tmp=0;
  for(int i=0;i<3;++i)
    tmp=tmp*10+t[i+j];
  if(tmp%5!=0) return false;

  j++;
  tmp=0;
  for(int i=0;i<3;++i)
    tmp=tmp*10+t[i+j];
  if(tmp%7!=0) return false;

  j++;
  tmp=0;
  for(int i=0;i<3;++i)
    tmp=tmp*10+t[i+j];
  if(tmp%11!=0) return false;

  j++;
  tmp=0;
  for(int i=0;i<3;++i)
    tmp=tmp*10+t[i+j];
  if(tmp%13!=0) return false;

  j++;
  tmp=0;
  for(int i=0;i<3;++i)
    tmp=tmp*10+t[i+j];
  if(tmp%17!=0) return false;

  return true;
}

int main(){
  long long res=0;
  do{
    if(prop()){
      long long tmp=0;
    for(int i=0;i<10;++i)
	tmp= 10*tmp + t[i];
    cout << tmp << '\n';
    res+=tmp;
    }
  }while(next_permutation(t,t+10));
  cout << "Résultat: " << res << '\n';
}
