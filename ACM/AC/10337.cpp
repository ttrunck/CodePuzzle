#include<iostream>
#include<vector>
#include<limits>

using namespace std;

const int N=100000;

int aux(const vector<vector<int> > & t, vector<vector<int> > & mem, int a, int d){
  if(d==-1) return (a==0?0:N);
  if(mem[a][d]!=N) return mem[a][d];
  int res=aux(t,mem,a,d-1)+30-t[a][d];
  if(a>0)
    res=min(res,aux(t,mem,a-1,d-1)+60-t[a-1][d]);
  if(a<9)
    res=min(res,aux(t,mem,a+1,d-1)+20-t[a+1][d]);
  return mem[a][d]=res;
}

int main(){
  int cas;
  cin >> cas;
  while(cas--){
    int d;
    cin >> d;
    vector<vector<int> > t(10,vector<int>(d/100,0));
    for(int i=9;i>=0;--i)
      for(int j=0;j<d/100;++j)
	cin >> t[i][j];
    vector<vector<int> > mem(10,vector<int>(d/100, N));
    
    cout << aux(t, mem, 0, d/100-1) << "\n\n";

  }
}
