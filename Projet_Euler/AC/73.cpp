#include<iostream>
#include<gmpxx.h>
#include<set>
#include<algorithm>

using namespace std;

typedef mpq_class f;

int const N=12000;

set<f> t;

int main(){
  for(int d=1;d<=N;++d)
    for(int n=d/3+1;2*n<d;++n){
      f tmp=n;
      t.insert(tmp/d);
    }


  //for(int i=0;i<t.size();++i)
  //  cout << t[i] << '\n';
  cout << t.size() << '\n';
}
