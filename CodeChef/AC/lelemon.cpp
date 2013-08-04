#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
  int T;
  cin >> T;
  while(T--){
    int n,m;
    cin >> n >> m;
    vector<int> dir(m);
    for(int i=0;i<m;++i)
      cin >> dir[i];
    vector<vector<int> > t(n);
    for(int i=0;i<n;++i){
      int c;
      cin >> c;
      t[i].resize(c);
      for(int j=0;j<c;++j)
	cin >> t[i][j];
    }

    for(int i=0;i<n;++i)
      sort(t[i].begin(), t[i].end());

    int res=0;
    for(int i=0;i<m;++i){
      if(!t[dir[i]].empty()){
	res+=t[dir[i]].back();
	t[dir[i]].pop_back();
      }
    }
    cout << res << '\n';
  }
}
