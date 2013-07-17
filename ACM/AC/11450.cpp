#include<iostream>

using namespace std;

int const N=209;
bool t[N];
bool tt[N];

void init(){
  for(int i=0;i<N;++i){
    t[i]=false;
    tt[i]=false;
  }
  t[0]=true;
}

int main(){
  int cas;
  cin >> cas;
  while(cas--){
    int M, C;
    cin >> M >> C;
    init();
    for(int c=0;c<C;++c){
      int K;
      cin >> K;
      for(int k=0;k<K;++k){
	int tmp;
	cin >> tmp;
	for(int i=0;i<=M;++i)
	  if(t[i] && i+tmp<=M)
	    tt[i+tmp]=true;
      }
      for(int i=0;i<=M;++i){
	t[i]=tt[i];
	tt[i]=false;
      }
    }
    int res=-1;
    for(int i=0;i<=M;++i)
      if(t[i]) res=i;
    if(res==-1) cout << "no solution" << endl;
    else cout << res << endl;
  }
}
