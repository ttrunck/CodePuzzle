#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

typedef pair<int, int> pi;

int main(){
  int T;
  cin >> T;
  while(T--){
    int n;
    cin >> n;
    vector<pi> t(n);
    for(int i=0;i<n;++i)
      cin >> t[i].first >> t[i].second;

    double v=0;
    for(int i=1;i<n;++i){
      double x=(t[i].first-t[i-1].first);
      double bas=min(t[i].second, t[i-1].second);
      double haut=max(t[i].second, t[i-1].second);
      v+=x*(-haut);
      v+=x*(haut-bas)/2;
    }

    int w;
    cin >> w;
    v*=w;

    double per, cons, reco;
    cin >> per >> cons >> reco;
    double vcurr=v*per/100;
    
    vcurr-=cons;
    if(vcurr<0){
      vcurr=0;
      cout << "Lack of water. ";
    }
    vcurr+=reco;
    if(vcurr>v){
      vcurr=v;
      cout << "Excess of water. ";
    }
    cout << "Final percentage: " << int(vcurr/v*100) << "%\n";
  }
}
