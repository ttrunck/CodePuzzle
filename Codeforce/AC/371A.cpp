#include<iostream>
#include<vector>

using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> t(n);
  for(int i=0;i<n;++i)
    cin >> t[i];

  int res=0;
  for(int i=0;i<k;++i){
    int nb1=0;
    for(int j=i;j<n;j+=k)
      if(t[j]==1)
	++nb1;
    res+=min(nb1, n/k-nb1);
  }


    cout << res << '\n';
}
