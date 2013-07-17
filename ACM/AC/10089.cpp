#include<iostream>
#include<vector>
#include<utility>
#include<cmath>
#include<algorithm>

using namespace std;

double angle(int x, int y){
  return atan2(y,x);
}

const double pi=atan2(0,-1);
const double epsi=10e-8;

int main(){
  int n;
  while(cin >> n && n){
    vector<double> t(n);
    for(int i=0;i<n;++i){
      int a,b,c;
      cin >> a >> b >> c;
      t[i]=angle(b-a, c-a);
    }
    sort(t.begin(), t.end());
    t.push_back(t[0]+2*pi);
    bool res=true;
    for(int i=0;i<n;++i)
      if(t[i+1]-t[i]-epsi>pi){
	res=false;
	break;
      }
   
    /* 
    for(int i=0;i<=n;++i)
      cerr << t[i]/pi*180 << ' ';
    cerr << endl;
    */
    if(res) cout << "Yes\n";
    else cout << "No\n";
  }
}
