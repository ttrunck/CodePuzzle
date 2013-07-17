#include<iostream>
#include<vector>
#include<gmpxx.h>

using namespace std;

typedef mpz_class ent;

const int N=25000;

int main(){
  vector<ent> t(3,1);
  for(int i=0;i<N;++i)
    t.push_back(t[i]+t[i+1]+t[i+2]);
  cerr << t[t.size()-1] << endl;

  int curr=1, nb=1;
  while(nb<=124){
    bool b=true;
    for(int j=0;j<int(t.size());++j)
      if(t[j]%(curr)==0){
	b=false;
	continue;
      }
    if(b){
    cout << nb << ": " << curr << '\n';
    nb++;
    }
    curr+=2;
  }
}
