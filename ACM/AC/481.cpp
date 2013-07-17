#include<iostream>
#include<vector>
#include<algorithm>

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
  vector<int> t;
  int tmp;
  while(cin >> tmp)
    t.push_back(tmp);
  vector<int> l;
  LIS(t,l);
  cout << int(l.size()) << "\n-\n";
  for(int i=0;i<int(l.size());++i)
    cout << l[i] << endl;
}
