#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> pi;

int main(){
  int nbcase;
  cin >> nbcase;
  while(nbcase--){
    int p, n;
    cin >> p >> n;
    vector<pi> t(n);
    for(int i=0;i<n;++i){
      cin >> t[i].first;
      t[i].second=-i;
    }

    int somme = 0;
    for(int i=0;i<n;++i)
      somme+=t[i].first;
    if(somme<p)
      cout << "IMPOSSIBLE\n";
    else{
      sort(t.begin(), t.end());
      vector<int> pay(n);
      for(int i=0;i<n;++i){
	int tmp=min(t[i].first, p/(n-i));
	pay[-t[i].second]=tmp;
	p-=tmp;
      }

      for(int i=0;i<n-1;++i)
	cout << pay[i] << ' ';
      cout << pay[n-1] << '\n';
    }
  }
}
