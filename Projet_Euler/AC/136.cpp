#include<iostream>
#include<vector>

using namespace std;

const int N=50000000;
const int sol=1; 

typedef long long ll;

int main(){
  vector<int> compt(N);

  for(ll u=1;u<N;++u)
    for(ll v=(u+2)/3+1;v*u<N;++v){
      if((u+v)%4==0 && (3*v-u)%4==0){
	//cerr << u << ' ' << v << endl;
	compt[u*v]++;
      }
    }
  
  int res=0;
  for(int x:compt)
    if(x==sol)
      res++;
  
  cout << res << endl;
}
