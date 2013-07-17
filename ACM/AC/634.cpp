#include<iostream>
#include<vector>

using namespace std;

typedef pair<int, int> pi;

inline bool intersec(const pi & a, const pi & b, const pi & c){
  return (c.second>min(a.second, b.second) 
	  && c.second<max(a.second, b.second)
	  && c.first<a.first);
}

int main(){
  int n;
  while(cin >> n && n){
    vector<pi> t(n);
    for(int i=0;i<n;++i)
      cin >> t[i].first >> t[i].second;
    t.push_back(t[0]);

    pi p;
    cin >> p.first >> p.second;
    int inter=0;

    for(int i=0;i<n;++i){
      if(t[i].first==t[i+1].first && intersec(t[i],t[i+1], p))
	inter++;
    }

    if(inter%2==0)
      cout << "F\n";
    else
      cout << "T\n";
  }
}
