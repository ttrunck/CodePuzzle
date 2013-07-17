#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>

using namespace std;

bool ok(int start, const vector<int> & t){
  for(int i=0;i<start;++i)
    if(t[i]==t[start])
      return false;

  for(int i=0;i<start;++i)
    if(start-i==abs(t[start]-t[i])) return false;
  
  return true;
}

int aux(int start, vector<int> & t, int change){
  if (start == 8) return change;
  int orig = t[start];
  int res=8;
  for(int i=1;i<=8;++i){
    t[start]=i;
    if(ok(start, t)){
      if(i==orig)
	res=min(res, aux(start+1, t, change));
      else
	res=min(res, aux(start+1, t, change+1));
    }
  }
  t[start]=orig;
  return res;
}

int main(){
  int icase=1;
  vector<int> t(8);
  while(cin >> t[0] >> t[1] >> t[2] >> t[3] >> t[4] >> t[5] >> t[6] >> t[7]){
    cout << "Case " << icase << ": ";
    cout << aux(0, t, 0) << '\n';
    ++icase;
  }
}
