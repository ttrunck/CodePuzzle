#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

bool poss(const vector<int>& t, int nb){
  int n=t.size();

  vector<int> pile(nb);
  int curr=0;
  for(int i=n-1;i>=n-1-nb+1;--i){
    pile[curr]=t[i];
    curr = (curr+1)%nb;
  }

  for(int i=n-1-nb;i>=0;--i){
    if(pile[curr]==0) return false;
    pile[curr]=min(pile[curr]-1, t[i]);
    curr = (curr+1)%nb;
  }

  return true;
}

int main(){
  int n;
  cin >> n;
  vector<int> t(n);
  for(int i=0;i<n;++i)
    cin >> t[i];
  sort(begin(t), end(t));

  for(int i=1;i<=n;++i)
    if(poss(t, i)){
      cout << i << '\n';
      return 0;
    }


}
