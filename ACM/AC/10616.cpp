#include<iostream>
#include<vector>

using namespace std;

typedef long long ent;

ent aux(ent n, const vector<ent> & t, ent d, ent m, ent val, vector<vector<vector<ent> > > & mem){
 
  if(val==0 && m==0) return 1;
  if(m<=0 || n==0) return 0;
  

  //cerr << n << ' ' << d << ' ' << m << ' ' << val << endl;
  if(mem[val][m][n]!=-1) return mem[val][m][n];
  ent res=0;
  
  res+=aux(n-1, t, d, m-1, (d+(val+t[n-1])%d)%d,mem);
  res+=aux(n-1, t, d, m, val, mem);

  mem[val][m][n]=res;
  return res;
}

int main(){
  ent N, Q;
  int iset = 1;
  while(cin >> N >> Q && (N||Q)){
    cout << "SET " << iset << ":\n";
    vector<ent> t(N);
    for(int i=0;i<N;++i)
      cin >> t[i];
    for(int iquery=1;iquery<=Q;++iquery){
      cout << "QUERY " << iquery << ": "; 
      ent D, M;
      cin >> D >> M;
      vector<vector<vector<ent> > > mem(D+1, vector<vector<ent> >(M+1, vector<ent>(N+1,-1)));
      cout << aux(N, t, D, M, 0, mem) << '\n';
	}
    ++iset;
  }
}
