#include<iostream>
#include<gmpxx.h>
#include<vector>
#include<algorithm>
using namespace std;

int const N=1000000;

vector<mpq_class> t;


int main(){
  for(int i=1;i<=N;++i)
    for(int j=3*i/7;j<3*i/7+1;++j){
      mpq_class tmp=j;
      t.push_back(tmp/i);
    }

  sort(t.begin(),t.end());

  vector<mpq_class>::iterator it;
    it = unique (t.begin(), t.end()); 
  t.resize( it - t.begin() ); 
  
  for(int i=t.size()-2;i<t.size();++i)
    cout << t[i] << ' ';
  cout << '\n';

}
