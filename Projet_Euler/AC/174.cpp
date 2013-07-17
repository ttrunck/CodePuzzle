#include<iostream>
#include<vector>

using namespace std;

const int N=1000000;
vector<int> t(N,0);

typedef long long ent;

void lamina(int trou, int tilde){
  int size=trou;
  int usetilde=0;
  while(usetilde+4*(size+1)<=tilde){
    usetilde=usetilde+4*(size+1);
    size+=2;
    t[usetilde]++;
  }
}

int main(){

  for(int i=1;i<N/2;++i)
    lamina(i,N);

  vector<ent> n(20,0);
  for(int i=0;i<N;++i)
    if(t[i]<20)
      n[t[i]]++;

  ent res=0;
  for(int i=1;i<=10;++i)
    res+=n[i];

  cout << res << endl;

}
