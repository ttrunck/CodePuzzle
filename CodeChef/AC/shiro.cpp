#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

double aux(int n, int target, vector<vector<double> >& mem, const vector<double>& a, const vector<double>& p){

  if(target<=0) return 1;
  if(n<0) return 0;
  
  if(mem[n][target]>-0.5)
    return mem[n][target];

  double res=0;

  res+= p[n]*aux(n-1, target-a[n], mem, a, p);
  res+= (1-p[n])*aux(n-1, target, mem, a, p);
 
  mem[n][target]=res;
  return res;
}

int main(){
  int T;
  cin >> T;
  while(T--){
    int n;
    cin >> n;
    vector<double> a(n);
    vector<double> p(n);
    int nb_drap=0;
    for(int i=0;i<n;++i){
      cin >> a[i];
      nb_drap+=a[i];
    }
    for(int i=0;i<n;++i){
      cin >> p[i];
      p[i]/=100;
    }

    vector<vector<double> > mem(n,vector<double>(nb_drap+2,-1));
    cout << aux(n-1, (nb_drap+1)/2, mem, a, p) << '\n';

  }
}
