#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
  int nbcase;
  cin >> nbcase;
  while(nbcase--){
    int n;
    cin >> n;
    vector<int> t(n);
    for(int i=0;i<n;++i)
      cin >> t[i];
    int k;
    cin >> k;
    int val=t[k-1];
    sort(begin(t), end(t));

    int res=1;
    while(t[res-1]!=val)res++;
    cout << res << '\n';
  }
}
