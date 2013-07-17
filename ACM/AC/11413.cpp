#include<iostream>
#include<vector>

using namespace std;

bool solved(int s, const vector<int> & t, int c){
  int nb=1;
  int curr=0;
  for(int i=0;i<int(t.size());++i){
    if(t[i]>s) return false;
    if(t[i]+curr<=s)
      curr+=t[i];
    else{
      nb++;
      if(nb>c) return false;
      curr=t[i];
    }
  }

  return true; 
}

int main(){
  int n,c;
  while(cin >> n >> c){
    vector<int> t(n);
    int lo=0, hi=0;
    for(int i=0;i<n;++i){
      cin >> t[i];
      hi+=t[i];
    }

    while(lo!=hi){
      if(solved((hi+lo)/2+1, t, c))
	hi=(hi+lo)/2;
      else
	lo=(hi+lo)/2+1;
    }
    
    cout << lo+1 << '\n';
  }
}
