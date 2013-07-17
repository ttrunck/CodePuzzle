#include<iostream>
#include<map>

using namespace std;

typedef long long ent;

const int N=1000000000;

bool palindrome(ent n){
  ent tmp=n;
  ent nn=0;
  while(tmp!=0){
    nn=nn*10+tmp%10;
    tmp/=10;
  }
  return nn==n;
}

int main(){
  map<ent, int> m;

  for(ent i=0;i*i*i<N;++i)
    for(ent j=0;i*i*i+j*j<N;++j){
      ent tmp=i*i*i+j*j;
      if(palindrome(tmp))
	m[tmp]++;
    }

  ent res=0;
  for(auto it=m.begin();it!=m.end();++it)
    if(it->second==4){
      cout << it->first << endl;
      res+=it->first;
    }
  cout << "res: " << res << endl;
}
