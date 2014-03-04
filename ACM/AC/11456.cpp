#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void LIS(const vector<int> &a, vector<int> &b){
  
  b=vector<int>(a.size(), 1);
  if (a.empty()) return;
    
  for(int i=int(a.size());i>=0; i--){
    for(int j=i+1;j<int(a.size());++j)
      if(a[j]>a[i])
	b[i]=max(b[i], b[j]+1);
  }
}

void LDS(const vector<int> &a, vector<int> &b){
  
  b=vector<int>(a.size(), 1);
  if (a.empty()) return;
    
  for(int i=int(a.size());i>=0; i--){
    for(int j=i+1;j<int(a.size());++j)
      if(a[j]<a[i])
	b[i]=max(b[i], b[j]+1);
  }
}

int main(){

  int cas;
  cin >> cas;
  while(cas--){
    int n;
    cin >> n;
    vector<int> t(n);
    for(int i=0;i<n;++i)
      cin >> t[i];

    vector<int> lis, lds;
    LIS(t,lis);
    LDS(t,lds);

    int res=0;
    for(int i=0;i<int(lis.size());++i){
      //cerr << i << ' ' << lis[i] << ' ' << lds[i] << endl;
	res=max(res, lis[i]+lds[i]-1);
    }
    cout << res << endl;
  }
}
