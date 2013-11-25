#include<iostream>
#include<vector>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> t(n);
  for(int i=0;i<n;++i)
    cin >> t[i];

  vector<vector<int> > d(n, vector<int>(n,0));
  for(int i=1;i<n;++i)
    for(int j=0;j<n;++j)
      d[i][j]=d[i-1][j]+((t[i-1]>j)?1:0);

  vector<vector<int> > e(n, vector<int>(n,0));
  for(int i=n-2;i>=0;--i)
    for(int j=0;j<n;++j)
      e[i][j]=e[i+1][j]+((t[i+1]<j)?1:0);


  int old=0;
  for(int i=0;i<n;i++)
    for(int j=0;j<i;j++)
      if(t[i]<t[j])
	old++;

  int res=old;
  int cnt=0;
  for(int i=0;i<n;++i)
    for(int j=i+1;j<n;++j){
      int nres = old-d[i][t[i]]+d[i][t[j]]-e[i][t[i]]+e[i][t[j]]
	-d[j][t[j]]+d[j][t[i]]-e[j][t[j]]+e[j][t[i]]+1;

      if(nres<res){
	res=nres;
	cnt=1;
      }
      else if(nres==res)
	cnt++;
    }
    
  cout << res << ' ' << cnt << '\n';

}
