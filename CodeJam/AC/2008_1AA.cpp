#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

void solve(){
  int t;
  cin >> t;
  vector<long long> v1(t), v2(t);
  for(int i=0;i<t;++i)
    cin >> v1[i];
  for(int i=0;i<t;++i)
    cin >> v2[i];
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());

  long long res=0;
  for(int i=0;i<t;++i)
    res+=v1[i]*v2[t-i-1];

    cout << res << '\n';
}

int main(){
  int N;
  cin >> N;
  cin.ignore();
  for(int icase=1;icase<=N;++icase){
    cout << "Case #" << icase << ": ";
    solve();
  }
}
