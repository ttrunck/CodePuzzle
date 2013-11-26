#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for(int i=0;i<n;++i)
    cin >> a[i];

  vector<int> res(n);
  set<int> curr;

  for(int i=n-1;i>=0;--i){
    curr.insert(a[i]);
    res[i]=curr.size();
  }

  for(int i=0;i<m;++i){
    int l;
    cin >> l;
    cout << res[l-1] << '\n';
  }
}
