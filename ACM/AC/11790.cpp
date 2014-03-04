#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>

using namespace std;

int LIS(const vector<int> & t, const vector<int> & w){
  int n=int(t.size());
  vector<int> m=w;

  for(int i=0;i<n;++i)
    for(int j=0;j<i;++j)
      if(t[j]<t[i])
	m[i]=max(m[j]+w[i], m[i]);

  int res=0;
  for(int i=0;i<n;++i)
    res=max(res, m[i]);

  return res;
}

int LDS(const vector<int> & t, const vector<int> & w){
  int n=int(t.size());
  vector<int> m=w;

  for(int i=0;i<n;++i)
    for(int j=0;j<i;++j)
      if(t[j]>t[i])
	m[i]=max(m[j]+w[i], m[i]);

  int res=0;
  for(int i=0;i<n;++i)
    res=max(res, m[i]);

  return res;
}


int main(){
  int icas;
  cin >> icas;
  for(int cas=1;cas<=icas;++cas){
    int n;
    cin >> n;
    vector<int> t(n), w(n);
    for(int i=0;i<n;++i)
      cin >> t[i];
    for(int i=0;i<n;++i)
      cin >> w[i];

    int lis=LIS(t,w), lds=LDS(t,w);
    if(lis>=lds)
      cout << "Case " << cas << ". Increasing (" << lis << "). Decreasing (" << lds << ")." << endl;
    else
      cout << "Case " << cas << ". Decreasing (" << lds << "). Increasing (" << lis << ")." << endl;
  }
}
