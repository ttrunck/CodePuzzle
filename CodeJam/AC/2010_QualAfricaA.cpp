#include<iostream>
#include<vector>

using namespace std;

void solve(){
  int c,l;
  cin >> c >> l;
  vector<int> t(l);
  for(int i=0;i<l;++i)
    cin >> t[i];

  for(int i=0;i<l;++i)
    for(int j=i+1;j<l;++j)
      if(t[i]+t[j]==c){
	cout << i+1 << ' ' << j+1 << '\n';
	return;
      }
}

int main(){
  int N;
  cin >> N;
  for(int icase=1;icase<=N;++icase){
    cout << "Case #" << icase << ": ";
    solve();
  }
}
