#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> pi;

int main(){
  int n;
  cin >> n;
  vector<pi> t(n);
  for(int i=0;i<n;++i){
    int tmp;
    cin >> tmp;
    t[i]=pi{tmp, i};
  }

  sort(begin(t), end(t));

  vector<int> rating(n,0);

  rating[0]=t[0].first;
  for(int i=1;i<n;++i)
    rating[i]=max(t[i].first, rating[i-1]+1);

  vector<int> res(n);
  for(int i=0;i<n;++i)
    res[t[i].second]=rating[i];

  cout << res[0];
  for(int i=1;i<n;++i)
    cout << ' ' << res[i];
  cout << '\n';
}
