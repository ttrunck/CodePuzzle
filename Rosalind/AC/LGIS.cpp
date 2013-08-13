#include<iostream>
#include<vector>

using namespace std;

void LIS(const vector<int> &x, vector<int> &b){
  if(x.empty()) return;
  
  vector<int> p(x.size());
  vector<int> m(1,0);

  for(int i=1;i<int(x.size());++i){
    if(x[i]>x[m.back()]){
      p[i]=m.back();
      m.push_back(i);
      continue;
    }  
    int lo=0, hi=m.size()-1;
    while(lo!=hi){
      int mid=(lo+hi)/2;
      if(x[m[mid]]<x[i]) lo=mid+1;
      else hi=mid;
    }
    p[i]=m[lo-1];
    if(x[i]<x[m[lo]])
      m[lo]=i;
  }

  int curr=m.back();
  int i=m.size();
  while(i--){
    b.push_back(x[curr]);
    curr=p[curr];
  }

  reverse(b.begin(), b.end());
}

int main(){
  int n;
  cin >> n;
  vector<int> t(n);
  for(int i=0;i<n;++i)
    cin >> t[i];

  vector<int> res;
  LIS(t,res);
  
  for(int i:res)
    cout << i << ' ';
  cout << '\n';

  for(int i=0;i<n;++i)
    t[i]=n-t[i];

  res.clear();
  LIS(t,res);
  for(int i:res)
    cout << n-i << ' ';
  cout << '\n';
  

}
