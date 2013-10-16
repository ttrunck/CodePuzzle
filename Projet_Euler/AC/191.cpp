#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

int good(int n, int k, int l, vector<vector<vector<int> > >& mem){
  if(n==0) return 1;

  if(mem[n][k][l]!=-1) return mem[n][k][l];

  int res=good(n-1,0,l,mem);

  if(l<1)
    res+=good(n-1,0,1,mem);
  if(k<2)
    res+=good(n-1,k+1,l,mem);

  return mem[n][k][l]=res;
}

int main(){

  vector<vector<vector<int> > > mem(31, vector<vector<int> >(4, vector<int>(2,-1)));
  cout << good(30,0,0,mem) << endl;

}
