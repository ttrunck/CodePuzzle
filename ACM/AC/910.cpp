#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int aux(vector<vector<int> > & mem, const vector<int> & t0, const vector<int> & t1, const vector<bool> & win, int s, int m){

  if(m==-1) return (win[s]?1:0);
  if(mem[s][m]!=-1) return mem[s][m];
  int res=aux(mem, t0, t1, win, t0[s],m-1);
  res+=aux(mem,t0,t1,win, t1[s],m-1);
  return mem[s][m]=res;
}

int main(){
  int n;
  while(cin >> n){
    vector<int> t0(n);
    vector<int> t1(n);
    vector<bool> win(n);
    char a,b,c,d;
    for(int i=0;i<n;++i){
      cin >> a >> b >> c >> d;
      t0[i]=b-'A';
      t1[i]=c-'A';
      win[i]=(d=='x');
    }
    int m;
    cin >> m;

    vector<vector<int> > mem(n,vector<int>(m,-1));
    
    cout << aux(mem,t0,t1,win,0,m-1) << '\n';

  }
}
