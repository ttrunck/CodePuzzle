#include<iostream>
#include<vector>

using namespace std;

int N,B;

bool ok(const vector<int> & t, int x){
  int b=B;
  for(int i=0;i<N;++i)
    b-=(t[i]+x-1)/x;
  return b>=0;
}

int main(){
  while(cin >> N >> B && (N!=-1 || B!=-1)){
    vector<int> p(N);
    int maxi=0;
    for(int i=0;i<N;++i){
      cin >> p[i];
      maxi=max(maxi, p[i]);
    }

    int lo=0, hi=maxi;
    while(lo!=hi){
    if(!ok(p, (lo+hi)/2))
      lo=(lo+hi)/2+1;
    else
      hi=(lo+hi)/2;
    }
    cout << lo << '\n';
  }
}
