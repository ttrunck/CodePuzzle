#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

void aux(int n, int k, vector<vector<bool> > & t){

  if(n==0) return;
  if(k==0){
    t=vector<vector<bool> >(1,vector<bool>(n,false));
    return;
  }
  if(n==k){
     t=vector<vector<bool> >(1,vector<bool>(n,true));
    return;
  }
  
  t.clear();
  vector<vector<bool> > tt;
  aux(n-1,k,tt);
  for(int i=0;i<int(tt.size());++i){
    tt[i].push_back(false);
    t.push_back(tt[i]);
  }
  aux(n-1,k-1,tt);
  for(int i=0;i<int(tt.size());++i){
    tt[i].push_back(true);
    t.push_back(tt[i]);
  }
}

double calc(const vector<double> & p, const vector<bool> & b){
  double res=1;
  for(int i=0;i<int(b.size());++i)
    if(b[i])
      res*=p[i];
    else
      res*=(1-p[i]);

  return res;
}

int main(){
  int n, r;
  int icase=1;
  while(cin >> n >> r && (n || r)){
    cout << "Case " << icase++ << ":\n";
    vector<vector<bool> > t;
    aux(n,r,t);
    vector<double> p(n);
    for(int i=0;i<n;++i)
      cin >> p[i];
    
    double ptot=0;
    vector<double> pcond(n,0);
    for(int i=0;i<int(t.size());++i){
      double tmp=calc(p, t[i]);
      ptot+=tmp;
      for(int j=0;j<int(t[i].size());++j)
	if(t[i][j])
	  pcond[j]+=tmp;
    }

    for(int i=0;i<int(pcond.size());++i)
      cout << setprecision(6) << fixed << pcond[i]/ptot << '\n';

  }
}
