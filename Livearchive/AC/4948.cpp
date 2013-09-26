#include<iostream>
#include<vector>
#include<set>

using namespace std;

typedef pair<int, int> pi;

int main(){
  int nbcase;
  cin >> nbcase;
  while(nbcase--){
    int n;
    cin >> n;
    vector<int> t(n);
    for(int i=0;i<n;++i)
      cin >> t[i];

    int m;
    cin >> m;
    set<pi> change;
    for(int i=0;i<m;++i){
      int a, b;
      cin >> a >> b;
      change.insert(pi(min(a,b),max(a,b)));
    }

    for(int j=0;j<n;++j)
      for(int i=1;i<n;++i){
	set<pi>::iterator it = change.find(pi(min(t[i-1], t[i]), max(t[i-1], t[i])));
	if(it!=change.end()){
	  swap(t[i-1], t[i]);
	  change.erase(it);
	}
      }

    if(!change.empty())
      cout << "IMPOSSIBLE\n";
    else{
      for(int i=0;i<n;++i)
	cout << t[i] << (i==n-1?'\n':' ');
    }
  }
}
