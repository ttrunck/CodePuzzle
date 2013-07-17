#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;

int main(){
  int icas;
  cin >> icas;
  while(icas--){
    int n;
    cin >> n;
    double mini=0;
    vector<double> t(n);
    for(int i=0;i<n;++i){
      cin >> t[i];
      mini+=2*t[i];
    }

    sort(t.begin(), t.end());
    
    do{
      vector<double> pos(n);
      pos[0]=0;
      for(int i=1;i<n;++i)
	for(int j=0;j<i;++j)
	  pos[i]=max(pos[i], pos[j]+2*sqrt(t[j]*t[i]));
      
      double xmin=0, xmax=0;
      for(int i=0;i<n;++i){
	xmin=min(xmin, pos[i]-t[i]);
	xmax=max(xmax, pos[i]+t[i]);
      }

      mini=min(mini, xmax-xmin);
    }while(next_permutation(t.begin(), t.end()));

    cout << fixed << setprecision(3) << mini << '\n';
  }
}
