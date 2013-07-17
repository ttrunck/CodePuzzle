#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

typedef pair<int, int> pi;

int main(){
  int s, n;
  cin >> s >> n;
  vector<pi> t(n);
  for(int i=0;i<n;++i)
    cin >> t[i].first >> t[i].second;


  sort(t.begin(), t.end());

  bool res=true;

  for(int i=0;i<n;++i){
    if(s>t[i].first)
      s+=t[i].second;
    else{
      res=false;
      break;
    }

  }

  if(res)
    cout << "YES\n";
  else
    cout << "NO\n";
}
