#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

//departure then arrival
typedef pair<int, int> pi;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while(T--){
    int n, k;
    cin >> n >> k;
    map<int, vector<pi> > tt;
    for(int i=0;i<n;++i){
      int a,b,c;
      cin >> a >> b >> c;
      tt[c-1].push_back(pi{b,a});
    }

    int res=0;
    for(auto& t:tt){
      sort(begin(t.second), end(t.second));
      int occTill=-1;
      for(pi& p:t.second)
	if(p.second>=occTill){
	  ++res;
	  occTill=p.first;
	}
    }

    cout << res << '\n';
  }
}
