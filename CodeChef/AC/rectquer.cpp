#include<iostream>
#include<vector>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<vector<vector<int> > > tsum(10, vector<vector<int> >(n+1, vector<int>(n+1)));
  for(int i=0;i<n;++i)
    for(int j=0;j<n;++j){
      int tmp;
      cin >> tmp;
      tsum[tmp-1][i+1][j+1]=1;
    }

  for(int k=0;k<10;++k)
    for(int i=0;i<n;++i)
      for(int j=0;j<n;++j)
	tsum[k][i+1][j+1]+=
	  tsum[k][i][j+1]+
	  tsum[k][i+1][j]-
	  tsum[k][i][j];

  int q;
  cin >> q;
  for(int i=0;i<q;++i){
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int res=0;
    for(int i=0;i<10;++i)
      if(tsum[i][x2][y2]-tsum[i][x1-1][y2]-tsum[i][x2][y1-1]+tsum[i][x1-1][y1-1]>0)
	++res;
    cout << res << '\n';
  }

}
