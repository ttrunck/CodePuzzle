#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool couvert(const vector<double> & t, double w, double taille){
  double start=0;
  for(int i=0;i<int(t.size());++i){
    if(start<t[i]-w/2) return false;
    start=t[i]+w/2;
  }
  if(start<taille) return false;

  return true;
}

int main(){
  int nx, ny;
  double w;
  while(cin >> nx >> ny >> w && (nx||ny||w)){
    vector<double> x(nx);
    for(int i=0;i<nx;++i)
      cin >> x[i];
    vector<double> y(ny);
    for(int i=0;i<ny;++i)
      cin >> y[i];
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    
    if(!couvert(x, w, 75) || !couvert(y, w, 100))
      cout << "NO\n";
    else
      cout << "YES\n";

  }
}
