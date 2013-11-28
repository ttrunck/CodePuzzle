#include<iostream>
#include<vector>

using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  vector<vector<int> > t(n, vector<int>(m));
  for(int i=0;i<n;++i)
    for(int j=0;j<m;++j)
      cin >> t[i][j];

  for(int i=0;i<n;++i)
    if(t[i][0]==1 || t[i][m-1]==1){
    cout << "2\n";
    return 0;
    }

  for(int i=0;i<m;++i)
    if(t[0][i]==1 || t[n-1][i]==1){
    cout << "2\n";
    return 0;
    }

  cout << "4\n";

}
